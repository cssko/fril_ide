#include "editortabmanager.h"

EditorTabManager::EditorTabManager(QWidget *parent) : QTabWidget(parent) {
    this->setTabsClosable(true);
    this->setMovable(true);
    connect(this, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
}

EditorTabManager::~EditorTabManager(){};

void EditorTabManager::closeTab(int tabID){
    // Close tab if it's not the only tab open
    if (this->count() !=1 ){
        this->removeTab(tabID);
    }
}

void EditorTabManager::newTab(QString fileName, QString fileText){
    //TODO: Check for duplicate tabs

    // Create new editor
    newEditor();

    // Add a tab with that editor
    int tabID = this->addTab(this->editor, tr(fileName.toStdString().c_str()));
    this->setCurrentIndex(tabID);

    // Set editor text to that of its corresponding file
    editor->setPlainText(fileText);

}

// Set up a new editor
void EditorTabManager::newEditor() {
  // Initialize a new editor
  QFontDatabase::addApplicationFont(":/resources/fonts/DejaVuSansMono.ttf");
  QFont font;
  font.setFamily("DejaVu Sans Mono");
  font.setFixedPitch(true);
  font.setPointSize(14);

  editor = new Editor;
  completer = new QCompleter(this);
  //TODO: completer->setModel(this->modelFromFile(":/resources/bip_list.txt"));
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
