#include "settingsdialog.h"

#include <QAbstractButton>
#include <QDialogButtonBox>
#include <QPushButton>

SettingsDialog::SettingsDialog(QWidget *parent) : QDialog(parent) {
  QDialogButtonBox *buttonBox =
      new QDialogButtonBox(QDialogButtonBox::Apply | QDialogButtonBox::Cancel |
                           QDialogButtonBox::Ok);
  // clang-format off
  connect(buttonBox->button(QDialogButtonBox::Apply), &QAbstractButton::clicked, this, &SettingsDialog::apply);
  connect(buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::accept);
  connect(buttonBox, &QDialogButtonBox::rejected, this, &SettingsDialog::reject);
  // clang-format on
  QGridLayout *layout = new QGridLayout;
}

void SettingsDialog::apply() {}
void SettingsDialog::accept() {}
void SettingsDialog::reject() {}
