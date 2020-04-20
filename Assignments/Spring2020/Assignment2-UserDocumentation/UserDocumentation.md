# User Documentation

### Table of Contents

- [Download the IDE](#download)
- Features
    - [Text Editor](#editor)
    - [Syntax Highlighting](#syntaxhighlighting)
    - [Folder View](#folderview)
    - [Console (under development)](#console)
    - [Settings (under development)](#settings)
    - [Help (under development)](#help)
 - [FAQs](#faqs)

<a name="download"></a>
## Download the IDE
To download the IDE, make sure you have access to git to get the project repository. You can download git [here](https://git-scm.com/downloads).
Get access to the [GitHub repo link](https://github.com/cssko/fril_ide/tree/dev).
The IDE is developed under [Qt](https://www.qt.io/). Install Qt Creator using the community version. Add the CMake compiler along with the Qt version during setup. After setup and installation, a maintenance tool will be enabled to add, update, and remove components. 
To build the project you will navigate the project directory: fril_ide/src  and open CMakeLists.txt in QtCreator.

<a name="editor"></a>
## Text Editor
Fril files can be opened and edited in the text editor. Multiple fril files can be opened using the tabbed editor feature.

<a name="syntaxhighlighting"></a>
## Syntax Highlighting
Regular expressions are used as the pattern for syntax highlighting. Fril predicates, variables, parenthesis, and other symbols make up the grammar.

<a name="folderview"></a>
## Folder View
The folder tree view lists all folders/files in the current working directory.

<a name="console"></a>
## Console (under development)
The console will be able to access the Fril interpreter session as well as having the ability to load Fril files. This is a work in progress.

<a name="settings"></a>
## Settings (under development)
The settings feature is a work in progress. One of the options underneath settings is to adjust the color theme across the view and text. We will be implementing lecture mode as well.

<a name="help"></a>
## Help (under development)
The help feature will help with providing Fril resources and documentation.This feature is work in progress. 

<a name="faqs"></a>
## FAQs

**How to Develop Features**
    * [QtWidget](https://doc.qt.io/qt-5/qwidget.html)
    * Qt Examples and Tutorials. (Check Examples section in QtCreator). 
    
**Fril Documentation**
    * [Learning Fril](https://docs.google.com/document/d/1G7tiSEn1rRSrj6Cf00uEVAQQzQzWx3WuMtbuo-iehC0/edit#heading=h.yztcc7hv7e6u)
    * [FRIL Course Material](https://eecs.ceas.uc.edu/~aralescu/323Fall2005/LECTURES/Fril_index.html)
    *  [FRIL Tutorial by Nick Sorrell](https://sorrell.github.io/files/Fril.pdf)
    * [Applications of Logic Programming in Software Engineering](https://pdfs.semanticscholar.org/66df/f3f769195dcc90b95d8556eb445ad76665bb.pdf)
    * [FRIL Syntax Highlighting XML by Garrett Scholtes](https://gist.github.com/scholtes/dd2680ce9dd10907e32a02f6d8b94cb2)



