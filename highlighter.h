#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QObject>
#include <QSyntaxHighlighter>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    Highlighter(QTextDocument* parent = nullptr);

protected:
    void highlightBlock(const QString& text) override;

private:
    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };

    QVector<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    // I need defs for: user predicates, numbers, constants,
    // Should I do rainbow delimiters?

    QTextCharFormat numberFormat;
    QTextCharFormat variableFormat;
    QTextCharFormat keywordFormat; // Build in predicates
    //QTextCharFormat classFormat; No classes in fril.
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat; // Strings ?
//    QTextCharFormat functionFormat; No functions in fril.
};

#endif // HIGHLIGHTER_H
