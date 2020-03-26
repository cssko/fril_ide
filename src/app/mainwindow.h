#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "editor.h"
#include "highlighter.h"
#include "editortabmanager.h"
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
  void setupEditorTabManager();
  void setupDockWidgets();
  void setupFileMenu();
  void setupHelpMenu();
  void setupToolBar();
  QAbstractItemModel *modelFromFile(const QString &fileName);

  QCompleter *completer = nullptr;
  EditorTabManager *editorTabManager;
  Highlighter *highlighter;
  QMenu *mainWindowMenu;
  QTreeView *fileTreeView;
};
#endif // MAINWINDOW_H
