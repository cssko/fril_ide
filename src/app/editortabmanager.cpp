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
    editor = new Editor;

    // Add a tab with that editor
    int tabID = this->addTab(this->editor, tr(fileName.toStdString().c_str()));
    this->setCurrentIndex(tabID);

    // Set editor text to that of its corresponding file
    editor->setPlainText(fileText);

}
