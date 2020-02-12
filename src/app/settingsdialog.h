#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H
#include <QDialog>
#include <QListWidget>
#include <QStackedLayout>

class SettingsDialog : public QDialog {
  Q_OBJECT
public:
  SettingsDialog(QWidget *parent = nullptr);

private:
  QListWidget *listWidget;
  QStackedLayout *stackedLayout;
  void accept() final;
  void reject() final;
  void cancel();
  void apply();
};

#endif // SETTINGSDIALOG_H
