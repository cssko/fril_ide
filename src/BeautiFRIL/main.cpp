#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  Q_INIT_RESOURCE(resources);
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
  QApplication app(argc, argv);
  // TODO: Do we want a splash screen?
  MainWindow window;
  window.show();
  return app.exec();
}
