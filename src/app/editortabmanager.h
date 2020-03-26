#ifndef EDITORTABMANAGER_H
#define EDITORTABMANAGER_H

#include<QTabWidget>
#include<QCompleter>
#include "editor.h"
#include "highlighter.h"

class EditorTabManager : public QTabWidget {
  Q_OBJECT

public:
  EditorTabManager(QWidget *parent = nullptr);
  ~EditorTabManager();

public slots:
  void setupEditorTabManager();
  void newTab(QString fileName, QString fileText);
  void newEditor();

private:
  Editor *editor;
  QCompleter *completer = nullptr;
  Highlighter *highlighter;

};

#endif // EDITORTABMANAGER_H
