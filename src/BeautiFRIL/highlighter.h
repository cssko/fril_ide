#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QObject>
#include <QRegularExpression>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>

class Highlighter : public QSyntaxHighlighter {
  Q_OBJECT
public:
  Highlighter(QTextDocument *parent = nullptr);

protected:
  void highlightBlock(const QString &text) override;

private:
  struct HighlightingRule {
    QRegularExpression pattern;
    QTextCharFormat format;
  };

  QVector<HighlightingRule> highlightingRules;
  QRegularExpression commentStartExpression;
  QRegularExpression commentEndExpression;
  QTextCharFormat numberFormat;
  QTextCharFormat variableFormat;
  QTextCharFormat keywordFormat; // Built in predicates (bips)
  QTextCharFormat singleLineCommentFormat;
  QTextCharFormat multiLineCommentFormat;
  QTextCharFormat quotationFormat; // Strings ?
};

#endif // HIGHLIGHTER_H
