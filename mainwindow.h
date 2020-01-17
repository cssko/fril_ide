#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "highlighter.h"

#include <QMainWindow>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void about();
    void newFile();
    void openFile(const QString &path = QString());

private:
    Ui::MainWindow *ui;

    void setupEditor();
    void setupFileMenu();
    void setupHelpMenu();

    QTextEdit* editor;
    Highlighter* highlighter;
};

#endif // MAINWINDOW_H
