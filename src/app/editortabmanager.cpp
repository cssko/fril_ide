#include "editortabmanager.h"

EditorTabManager::EditorTabManager(QWidget *parent) : QTabWidget(parent) {}
EditorTabManager::~EditorTabManager(){};


void EditorTabManager::setupEditorTabManager(){
}

void EditorTabManager::newTab(QString fileName, QString fileText){
    newEditor();
    this->addTab(this->editor, tr(fileName.toStdString().c_str()));
    editor->setPlainText(fileText);
}

// Set up a new editor
void EditorTabManager::newEditor() {
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
