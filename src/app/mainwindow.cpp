#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QtWidgets>

// Tree view
#include <QFileIconProvider>
#include <QFileSystemModel>
#include <QTreeView>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  // TODO: this is going to set off deprecation warnings and should maybe also
  // be in a function.
  QSize availableSize = QGuiApplication::primaryScreen()->size();
  int width = availableSize.width() * 0.75;
  int height = availableSize.height() * 0.75;
  QSize newSize(width, height);

  setGeometry(QStyle::alignedRect(
      Qt::LeftToRight, Qt::AlignCenter, newSize,
      QGuiApplication::primaryScreen()->availableGeometry()));
  this->setupFileMenu();
  this->setupHelpMenu();
  this->setupEditor();
  this->setupEditorTabs();
  this->setCentralWidget(this->tabWidget);
  this->setWindowTitle(tr("BeautiFRIL"));
  this->setupDockWidgets();
}

void MainWindow::about() {
  QMessageBox::about(this, tr("About BeautiFRIL"),
                     tr("<p><b>BeautiFRIL</b> is an excellent example "
                        "of Mankinds hubris. </p>"));
}

void MainWindow::newFile() {
    int numTabs = tabWidget->count();
    tabWidget->addTab(this->editor, tr("New File"));
    tabWidget->setCurrentIndex(numTabs);
    editor->clear();
}

void MainWindow::openFile(const QString &path) {
  QString fileName = path;
  if (fileName.isNull())
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                            "Fril Files (*.frl *.frm)");
  if (!fileName.isEmpty()) {
    tabWidget->addTab(this->editor, tr(fileName.toStdString().c_str()));
    QFile file(fileName);
    if (file.open(QFile::ReadOnly | QFile::Text))
      editor->setPlainText(file.readAll());
  }
}

void::MainWindow::setupEditorTabs() {
    // Maybe we should move the TabWidget into its own class
    // The class could potentially handle opening new files,
    // closing and saving tabs, and generating editors for each tab
    tabWidget = new QTabWidget;
    tabWidget->addTab(this->editor, tr("New File"));
}

void MainWindow::setupEditor() {
  QFontDatabase::addApplicationFont(":/resources/fonts/DejaVuSansMono.ttf");
  QFont font;
  font.setFamily("DejaVu Sans Mono");
  font.setFixedPitch(true);
  font.setPointSize(14);

  editor = new Editor;
  completer = new QCompleter(this);
  completer->setModel(this->modelFromFile(":/resources/bip_list.txt"));
  completer->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
  completer->setCaseSensitivity(Qt::CaseInsensitive);
  completer->setWrapAround(false);
  editor->setCompleter(completer); //  editor->setAcceptRichText(false);
  editor->setFont(font);
  editor->setStyleSheet(
      "QTextEdit { background-color: #333333; color: white; }");
  editor->setTabStopDistance(20); // half size
  highlighter = new Highlighter(editor->document());
}

void MainWindow::setupDockWidgets() {
  // TODO: TreeView performance is not great out of the box, I'm probably
  // showing far too much. This also needs pulled out so that this doesn't
  // become a giant hellfunction.
  QDockWidget *fileTreeDock = new QDockWidget(tr("Tree View"), this);
  // TODO: Change name to QDir::current().dirName() as you navigate?
  fileTreeDock->setAllowedAreas(Qt::LeftDockWidgetArea |
                                Qt::RightDockWidgetArea);
  fileTreeDock->setFeatures(QDockWidget::DockWidgetMovable);

  QFileSystemModel *model = new QFileSystemModel;
  model->setRootPath(QDir::currentPath());
  model->setFilter(QDir::AllEntries | QDir::AllDirs | QDir::NoDotAndDotDot);
  QModelIndex indexPath = model->index(QDir::currentPath());
  QTreeView *fileTreeView = new QTreeView;

  fileTreeView->setModel(model);
  fileTreeView->setRootIndex(indexPath);
  // TODO: We want the ./.. options to go
  // up a directory and whatnot. - Do we actually?
  // Will want some kind of File->open directory too probably.
  //  fileTreeView->scrollTo(indexPath);
  fileTreeView->setAnimated(false);
  fileTreeView->setHeaderHidden(true);
  fileTreeView->setIndentation(10);
  fileTreeView->setSortingEnabled(true);
  fileTreeView->sortByColumn(0, Qt::SortOrder::AscendingOrder);
  // TODO: Let's not hide columns mystically, I hate this shit.
  fileTreeView->hideColumn(1);
  fileTreeView->hideColumn(2);
  fileTreeView->hideColumn(3);
  // TODO: Should have this resize based on dock size instead of screen size.
  //    const QSize availableSize =
  //        fileTreeView->screen()->availableGeometry().size();
  //    fileTreeView->resize(availableSize / 2);
  //    fileTreeView->setColumnWidth(0, fileTreeView->width() / 3);
  fileTreeDock->setWidget(fileTreeView);

  // ===== Console
  // TODO: This stinks
  QPlainTextEdit *frilConsole = new QPlainTextEdit;
  QPalette p = palette();
  p.setColor(QPalette::Base, Qt::black);
  p.setColor(QPalette::Text, Qt::green);
  frilConsole->setPalette(p);
  frilConsole->document()->setMaximumBlockCount(250);
  QDockWidget *consoleDock = new QDockWidget(tr("Console"), this);
  consoleDock->setAllowedAreas(Qt::AllDockWidgetAreas);
  consoleDock->setFeatures(QDockWidget::DockWidgetMovable);
  consoleDock->setWidget(frilConsole);

  addDockWidget(Qt::LeftDockWidgetArea, fileTreeDock);
  addDockWidget(Qt::BottomDockWidgetArea, consoleDock);
}

void MainWindow::setupFileMenu() {
  QMenu *fileMenu = new QMenu(tr("&File"), this);
  menuBar()->addMenu(fileMenu);

  fileMenu->addAction(tr("&New"), this, &MainWindow::newFile,
                      QKeySequence::New);
  fileMenu->addAction(
      tr("&Open..."), this, [this]() { openFile(); }, QKeySequence::Open);
  fileMenu->addAction(tr("E&xit"), qApp, &QApplication::quit,
                      QKeySequence::Quit);
}

void MainWindow::setupHelpMenu() {
  QMenu *helpMenu = new QMenu(tr("&Help"), this);
  menuBar()->addMenu(helpMenu);

  helpMenu->addAction(tr("&About"), this, &MainWindow::about);
  helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
}

QAbstractItemModel *MainWindow::modelFromFile(const QString &fileName) {
  QFile file(fileName);
  if (!file.open(QFile::ReadOnly)) {
    qInfo("readonly");
    return new QStringListModel(completer);
  }
#ifndef QT_NO_CURSOR
  QGuiApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
#endif
  QStringList words;

  while (!file.atEnd()) {
    QByteArray line = file.readLine();
    if (!line.isEmpty())
      words << QString::fromUtf8(line.trimmed());
  }

#ifndef QT_NO_CURSOR
  QGuiApplication::restoreOverrideCursor();
#endif
  return new QStringListModel(words, completer);
}

MainWindow::~MainWindow() {}
