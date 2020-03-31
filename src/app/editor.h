#ifndef EDITOR_H
#define EDITOR_H

#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QApplication>
#include <QCompleter>
#include <QKeyEvent>
#include <QModelIndex>
#include <QScrollBar>
#include <QtDebug>
#include <QStringListModel>
#include <QCompleter>
#include <QFocusEvent>
#include <QKeyEvent>
#include <QTextEdit>
#include <QListWidget>
#include <QFontDatabase>
#include "highlighter.h"


class Editor : public QTextEdit {
  Q_OBJECT
public:
  Editor(QWidget *parent = nullptr);
  ~Editor();

  void setCompleter(QCompleter *c);

protected:
  void keyPressEvent(QKeyEvent *e) override;
  void focusInEvent(QFocusEvent *e) override;

private slots:
  void insertCompletion(const QString &completion);

private:
  QString textUnderCursor() const;
  QAbstractItemModel *modelFromFile(const QString &fileName);


private:
  QCompleter *completer = nullptr;
  QCompleter *c = nullptr;
  Highlighter *highlighter;
};

#endif // EDITOR_H
