/*
PlantUML - Modelagem UML ESTRUTURADA
@startuml
title Sistema de Biblioteca - UML Estruturada
class Book {
  - int id
  - string title
  - string author
  - string isbn
  - bool available
  + Book(int, string, string, string)
  + bool isAvailable()
}
class Member {
  - int id
  - string name
  - string email
  + Member(int, string, string)
}
class Loan {
  - int id
  - Book* book
  - Member* member
  - string loanDate
  - string dueDate
  + Loan(int, Book*, Member*, string, string)
}
class Library {
  - map<int, Book> books
  - map<int, Member> members
  - map<int, Loan> loans
  + addBook(Book)
  + removeBook(int)
  + registerMember(Member)
  + checkout(int bookId, int memberId)
  + returnBook(int loanId)
  + searchByTitle(string): vector<Book>
}

Library "1" o-- "*" Book : contains
Library "1" o-- "*" Member : registers
Library "1" o-- "*" Loan : manages
Member "1" -- "*" Loan : takes
Book "1" -- "0..1" Loan : loaned
@enduml

Descrição resumida:
- Book: representa um livro (id, título, autor, ISBN, disponibilidade).
- Member: representa um usuário cadastrado.
- Loan: registro de empréstimo entre Book e Member.
- Library: fachada/gerenciador que mantém coleções e operações (CRUD básico e empréstimos).

*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <optional>
#include <algorithm>

using namespace std;

// --- Entidades ---
struct Book {
    int id;
    string title;
    string author;
    string isbn;
    bool available;

    Book() = default;
    Book(int _id, const string& _title, const string& _author, const string& _isbn)
        : id(_id), title(_title), author(_author), isbn(_isbn), available(true) {}
};

struct Member {
    int id;
    string name;
    string email;

    Member() = default;
    Member(int _id, const string& _name, const string& _email)
        : id(_id), name(_name), email(_email) {}
};

struct Loan {
    int id;
    int bookId;
    int memberId;
    string loanDate; // string simplificado; em produção usar chrono/data apropriada
    string dueDate;

    Loan() = default;
    Loan(int _id, int _bookId, int _memberId, const string& _loanDate, const string& _dueDate)
        : id(_id), bookId(_bookId), memberId(_memberId), loanDate(_loanDate), dueDate(_dueDate) {}
};

// --- Biblioteca ---
class Library {
private:
    map<int, Book> books;      // chave: book id
    map<int, Member> members;  // chave: member id
    map<int, Loan> loans;      // chave: loan id

    int nextBookId = 1;
    int nextMemberId = 1;
    int nextLoanId = 1;

public:
    // Adiciona um livro e retorna o id gerado
    int addBook(const string& title, const string& author, const string& isbn) {
        int id = nextBookId++;
        books.emplace(id, Book{id, title, author, isbn});
        return id;
    }

    bool removeBook(int bookId) {
        auto it = books.find(bookId);
        if (it == books.end()) return false;
        // prevenir remoção se emprestado
        if (!it->second.available) return false;
        books.erase(it);
        return true;
    }

    optional<Book> getBook(int bookId) const {
        auto it = books.find(bookId);
        if (it == books.end()) return nullopt;
        return it->second;
    }

    vector<Book> searchByTitle(const string& term) const {
        vector<Book> result;
        for (const auto& [id, b] : books) {
            if (b.title.find(term) != string::npos) result.push_back(b);
        }
        return result;
    }

    int registerMember(const string& name, const string& email) {
        int id = nextMemberId++;
        members.emplace(id, Member{id, name, email});
        return id;
    }

    optional<Member> getMember(int memberId) const {
        auto it = members.find(memberId);
        if (it == members.end()) return nullopt;
        return it->second;
    }

    // Realiza checkout: retorna id do empréstimo ou nullopt se falhar
    optional<int> checkout(int bookId, int memberId, const string& loanDate, const string& dueDate) {
        auto bIt = books.find(bookId);
        if (bIt == books.end()) return nullopt;
        if (!bIt->second.available) return nullopt;
        auto mIt = members.find(memberId);
        if (mIt == members.end()) return nullopt;

        int id = nextLoanId++;
        loans.emplace(id, Loan{id, bookId, memberId, loanDate, dueDate});
        bIt->second.available = false;
        return id;
    }

    bool returnBook(int loanId) {
        auto lIt = loans.find(loanId);
        if (lIt == loans.end()) return false;
        int bookId = lIt->second.bookId;
        auto bIt = books.find(bookId);
        if (bIt != books.end()) bIt->second.available = true;
        loans.erase(lIt);
        return true;
    }

    vector<Loan> listLoans() const {
        vector<Loan> out;
        out.reserve(loans.size());
        for (const auto& [id, l] : loans) out.push_back(l);
        return out;
    }

    vector<Book> listAvailableBooks() const {
        vector<Book> out;
        for (const auto& [id, b] : books) if (b.available) out.push_back(b);
        return out;
    }

    // Funções utilitárias para demonstração/depuração
    void printAvailableBooks() const {
        cout << "Livros disponíveis:\n";
        for (const auto& [id, b] : books) {
            if (b.available) cout << "  [" << id << "] " << b.title << " - " << b.author << "\n";
        }
    }

    void printMembers() const {
        cout << "Membros cadastrados:\n";
        for (const auto& [id, m] : members) cout << "  [" << id << "] " << m.name << " (" << m.email << ")\n";
    }

    void printLoans() const {
        cout << "Emprestimos ativos:\n";
        for (const auto& [id, l] : loans) {
            cout << "  [loan:" << id << "] bookId=" << l.bookId << " memberId=" << l.memberId
                 << " loanDate=" << l.loanDate << " due=" << l.dueDate << "\n";
        }
    }
};

// --- Exemplo de uso ---
int main() {
    Library lib;

    int b1 = lib.addBook("Estruturas de Dados", "A. Autor", "978-0001");
    int b2 = lib.addBook("Programacao em C++", "B. Escritor", "978-0002");

    int m1 = lib.registerMember("Joao Silva", "joao@example.com");
    int m2 = lib.registerMember("Maria Souza", "maria@example.com");

    lib.printAvailableBooks();
    lib.printMembers();

    auto loanOpt = lib.checkout(b2, m1, "2025-11-23", "2025-12-07");
    if (loanOpt) cout << "Checkout realizado. Loan id = " << *loanOpt << "\n";
    else cout << "Falha no checkout\n";

    lib.printAvailableBooks();
    lib.printLoans();

    if (loanOpt) {
        lib.returnBook(*loanOpt);
        cout << "Livro retornado.\n";
    }

    lib.printAvailableBooks();

    return 0;
}
