#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "editor.h"
#include "highlighter.h"
#include <QListWidget>
#include <QMainWindow>
#include <QStackedLayout>

// TODO: Why do we bother forward declaring these
QT_FORWARD_DECLARE_CLASS(QMenu)
QT_FORWARD_DECLARE_CLASS(QTreeView)

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

public slots:
  void about();
  void newFile();
  void openFile(const QString &path = QString());

private:
  QListWidget prefList;
  QStackedLayout prefLayout;
  // Not sure if we want to do the editor business here, as we may end up
  // having tabbed editors
  void setupEditor();
  void setupDockWidgets();
  void setupFileMenu();
  void setupHelpMenu();
  void setupToolBar();
  QAbstractItemModel *modelFromFile(const QString &fileName);

  QCompleter *completer = nullptr;
  Editor *editor;
  Highlighter *highlighter;
  QMenu *mainWindowMenu;
  QTreeView *fileTreeView;
};
#endif // MAINWINDOW_H
