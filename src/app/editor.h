#ifndef EDITOR_H
#define EDITOR_H

#include <QCompleter>
#include <QFocusEvent>
#include <QKeyEvent>
#include <QTextEdit>

class Editor : public QTextEdit {
  Q_OBJECT
public:
  Editor(QWidget *parent = nullptr);
  ~Editor();

  void setCompleter(QCompleter *c);
  QCompleter *completer() const;

protected:
  void keyPressEvent(QKeyEvent *e) override;
  void focusInEvent(QFocusEvent *e) override;

private slots:
  void insertCompletion(const QString &completion);

private:
  QString textUnderCursor() const;

private:
  QCompleter *c = nullptr;
};

#endif // EDITOR_H
