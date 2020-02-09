#include "mainwindow.h"
#include <QApplication>

#define BEAUTIFRIL_VERSION_STR "0.0.1a"

int main(int argc, char *argv[]) {
  Q_INIT_RESOURCE(resources);
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
  QApplication app(argc, argv);
  // TODO: Agree on how we want to handle versioning.
  QCoreApplication::setOrganizationName("BeautiFRIL Team");
  QCoreApplication::setApplicationName("BeautiFRIL");
  QCoreApplication::setApplicationVersion(BEAUTIFRIL_VERSION_STR);
  // TODO: Do we want a splash screen?
  MainWindow window;
  window.show();
  return app.exec();
}
