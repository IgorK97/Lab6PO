// Lab6PO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <memory>
#include <Windows.h>
using namespace std;
class Theme {
public:
    virtual ~Theme() = default;
    virtual void renderHeader(string a) = 0;
    virtual void renderBody(string a) = 0;
    virtual void renderFooter(string a) = 0;
};

class LightTheme : public Theme {
public:
    void renderHeader(string a) override {
        cout << a << " (заголовок в светлой теме)" << endl;
    }
    void renderBody(string a) override {
        cout << "-----------------" << endl;
        cout << a << " (в светлой теме)" << endl;
        cout << "-----------------" << endl;

    }
    void renderFooter(string a) override {
        cout << a << " (в светлой теме)" << endl;
    }
};

class DarkTheme : public Theme {
public:
    void renderHeader(string a) override {
        cout << a << " (заголовок в темной теме)" << endl;

    }
    void renderBody(string a) override {
        cout << "-----------------" << endl;
        cout << a << " (в темной теме)" << endl;
        cout << "-----------------" << endl;

    }
    void renderFooter(string a) override {
        cout << a << " (в темной теме)" << endl;
    }
};

class WebPage {
protected:
    Theme* theme;
    string header, body, footer;
public:
    virtual ~WebPage() = default;
    WebPage(Theme* theme, string header, string body, string footer) /*:theme(move(theme))*/ {
        this->theme = theme;
        this->header = header;
        this->footer = footer;
        this->body = body;
    }
    virtual void openPage() {
        theme->renderHeader(header);
        theme->renderBody(body);
        theme->renderFooter(footer);
    }
    void setTheme(Theme* newTheme) {
        theme = move(newTheme);
    }
    virtual void closePage() = 0;
};

class HomePage : public WebPage {
public:
    HomePage(Theme* theme, string header, string body, string footer) 
        : WebPage(theme, header, body, footer) {}
    void openPage() override {
        cout << "Открытие главной страницы: " << endl;
        WebPage::openPage();
    }
    void closePage() override {
        cout << "Закрываем главную страницу" << endl;
    }
};

class AboutWebSite : public WebPage {
public:
    AboutWebSite(Theme* theme, string header, string body, string footer) 
        : WebPage(theme, header, body, footer) {}
    void openPage() override {
        cout << "Открытие страницы о сайте: " << endl;
        WebPage::openPage();
    }
    void closePage() override {
        cout << "Закрываем страницу о сайте" << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Theme* lightTheme = new LightTheme();
    Theme* darkTheme = new DarkTheme();

    HomePage homePage(lightTheme, "ЗАГОЛОВОК ГЛАВНОЙ СТРАНИЦЫ", "Основное содержание главной страницы",
        "Подвал главной страницы");
    AboutWebSite aboutWebSite(darkTheme, "ЗАГОЛОВОК СТРАНИЦЫ О САЙТЕ", 
        "Основное содержание страницы о сайте", "Подвал страницы о сайте");
    homePage.openPage();
    cout << endl;
    homePage.closePage();
    cout << endl;
    aboutWebSite.openPage();
    cout << endl;
    aboutWebSite.closePage();
    cout << endl;

    homePage.setTheme(darkTheme);

    cout << "Сменили тему главной страницы на темную" << endl;

    homePage.openPage();
    cout << endl;
    homePage.closePage();
    cout << endl;

    aboutWebSite.setTheme(lightTheme);

    cout << "Сменили тему страницы о сайте на светлую" << endl;

    aboutWebSite.openPage();
    cout << endl;
    aboutWebSite.closePage();
    cout << endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
