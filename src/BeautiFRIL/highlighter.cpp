#include "highlighter.h"

Highlighter::Highlighter(QTextDocument *parent) : QSyntaxHighlighter(parent) {
  HighlightingRule rule;
  keywordFormat.setForeground(
      QColor("#f0dfaf")); // TODO: Don't hardcode this, dork.

  // clang-format off
      
      const QString keywordPatterns[] = {
          QStringLiteral("\\babort\\b"),                QStringLiteral("\\baddcl\\b"),
          QStringLiteral("\\band\\b"),                  QStringLiteral("\\batomic\\b"),
          QStringLiteral("\\bcd\\b"),                   QStringLiteral("\\bcdict\\b"),
          QStringLiteral("\\bcharof\\b"),               QStringLiteral("\\bcl\\b"),
          QStringLiteral("\\bclose\\b"),                QStringLiteral("\\bcomplement\\b"),
          QStringLiteral("\\bcon\\b"),                  QStringLiteral("\\bconj\\b"),
          QStringLiteral("\\bconvert\\b"),              QStringLiteral("\\bcos\\b"),
          QStringLiteral("\\bcprintf\\b"),              QStringLiteral("\\bcputime\\b"),
          QStringLiteral("\\bcreate\\b"),               QStringLiteral("\\bcreate_a\\b"),
          QStringLiteral("\\bcreate_r\\b"),             QStringLiteral("\\bcreate_ra\\b"),
          QStringLiteral("\\bcscanf\\b"),               QStringLiteral("\\bdate\\b"),
          QStringLiteral("\\bddict\\b"),                QStringLiteral("\\bdef\\b"),
          QStringLiteral("\\bdef_dtype\\b"),            QStringLiteral("\\bdef_itype\\b"),
          QStringLiteral("\\bdef_rel\\b"),              QStringLiteral("\\bdelcl\\b"),
          QStringLiteral("\\bdempdict\\b"),             QStringLiteral("\\bdempster\\b"),
          QStringLiteral("\\bdict\\b"),                 QStringLiteral("\\bdisj\\b"),
          QStringLiteral("\\bdivision\\b"),             QStringLiteral("\\bdtype\\b"),
          QStringLiteral("\\bdtype_name\\b"),           QStringLiteral("\\bdtype_to_freq\\b"),
          QStringLiteral("\\bdtype_to_list\\b"),        QStringLiteral("\\bdynamic\\b"),
          QStringLiteral("\\bedict\\b"),                QStringLiteral("\\beq\\b"),
          QStringLiteral("\\berrm\\b"),                 QStringLiteral("\\berror\\b"),
          QStringLiteral("\\berr_han\\b"),              QStringLiteral("\\bevlog\\b"),
          QStringLiteral("\\bexists\\b"),               QStringLiteral("\\bexit\\b"),
          QStringLiteral("\\bexp\\b"),                  QStringLiteral("\\bexpected_value\\b"),
          QStringLiteral("\\bexport\\b"),               QStringLiteral("\\bfail\\b"),
          QStringLiteral("\\bfdict\\b"),                QStringLiteral("\\bfile\\b"),
          QStringLiteral("\\bfilebcopy\\b"),            QStringLiteral("\\bfilename\\b"),
          QStringLiteral("\\bfilepos\\b"),              QStringLiteral("\\bfilesearch\\b"),
          QStringLiteral("\\bfindall\\b"),              QStringLiteral("\\bflush\\b"),
          QStringLiteral("\\bfmem\\b"),                 QStringLiteral("\\bforall\\b"),
          QStringLiteral("\\bfset\\b"),                 QStringLiteral("\\bfsetdict\\b"),
          QStringLiteral("\\bfset_name\\b"),            QStringLiteral("\\bgen\\b"),
          QStringLiteral("\\bgeneral\\b"),              QStringLiteral("\\bgensym\\b"),
          QStringLiteral("\\bget\\b"),                  QStringLiteral("\\bgetb\\b"),
          QStringLiteral("\\bgetenv\\b"),               QStringLiteral("\\bget_prior\\b"),
          QStringLiteral("\\bget_univ\\b"),             QStringLiteral("\\bhelp\\b"),
          QStringLiteral("\\bhelp_example\\b"),         QStringLiteral("\\bidict\\b"),
          QStringLiteral("\\bif\\b"),                   QStringLiteral("\\bimport\\b"),
          QStringLiteral("\\binit_random\\b"),          QStringLiteral("\\bint\\b"),
          QStringLiteral("\\bintersection\\b"),         QStringLiteral("\\bintok\\b"),
          QStringLiteral("\\bisall\\b"),                QStringLiteral("\\bitype\\b"),
          QStringLiteral("\\bitype_name\\b"),           QStringLiteral("\\bitype_to_freq\\b"),
          QStringLiteral("\\bitype_to_list\\b"),        QStringLiteral("\\bkb_garbage\\b"),
          QStringLiteral("\\bkill\\b"),                 QStringLiteral("\\bless\\b"),
          QStringLiteral("\\bless_eq\\b"),              QStringLiteral("\\blist\\b"),
          QStringLiteral("\\blistfile\\b"),             QStringLiteral("\\blload\\b"),
          QStringLiteral("\\bload\\b"),                 QStringLiteral("\\blreload\\b"),
          QStringLiteral("\\bmatch\\b"),                QStringLiteral("\\bmaximise_frame\\b"),
          QStringLiteral("\\bmdict\\b"),                QStringLiteral("\\bmodule\\b"),
          QStringLiteral("\\bmodule_initialisation\\b"),QStringLiteral("\\bname\\b"),
          QStringLiteral("\\bneg\\b"),                  QStringLiteral("\\bnegg\\b"),
          QStringLiteral("\\bnospy\\b"),                QStringLiteral("\\bnot\\b"),
          QStringLiteral("\\bnum\\b"),                  QStringLiteral("\\boh\\b"),
          QStringLiteral("\\bopen\\b"),                 QStringLiteral("\\bor\\b"),
          QStringLiteral("\\borr\\b"),                  QStringLiteral("\\bos\\b"),
          QStringLiteral("\\bosc\\b"),                  QStringLiteral("\\bose\\b"),
          QStringLiteral("\\bosv\\b"),                  QStringLiteral("\\bp\\b"),
          QStringLiteral("\\bpeek\\b"),                 QStringLiteral("\\bpeekb\\b"),
          QStringLiteral("\\bpoint_match\\b"),          QStringLiteral("\\bposs_match\\b"),
          QStringLiteral("\\bpower\\b"),                QStringLiteral("\\bpp\\b"),
          QStringLiteral("\\bppq\\b"),                  QStringLiteral("\\bpq\\b"),
          QStringLiteral("\\bprlen\\b"),                QStringLiteral("\\bpspaces\\b"),
          QStringLiteral("\\bputb\\b"),                 QStringLiteral("\\bqh\\b"),
          QStringLiteral("\\bqs\\b"),                   QStringLiteral("\\bqsc\\b"),
          QStringLiteral("\\bqse\\b"),                  QStringLiteral("\\bqsv\\b"),
          QStringLiteral("\\br\\b"),                    QStringLiteral("\\brandom\\b"),
          QStringLiteral("\\brdict\\b"),                QStringLiteral("\\bread\\b"),
          QStringLiteral("\\bread_suppterm\\b"),        QStringLiteral("\\breload\\b"),
          QStringLiteral("\\bremainder\\b"),            QStringLiteral("\\brepeat\\b"),
          QStringLiteral("\\bsc\\b"),                   QStringLiteral("\\bse\\b"),
          QStringLiteral("\\bset\\b"),                  QStringLiteral("\\bsetenv\\b"),
          QStringLiteral("\\bset_difference\\b"),       QStringLiteral("\\bsh\\b"),
          QStringLiteral("\\bsin\\b"),                  QStringLiteral("\\bsnips\\b"),
          QStringLiteral("\\bspy\\b"),                  QStringLiteral("\\bspying\\b"),
          QStringLiteral("\\bsquare\\b"),               QStringLiteral("\\bstatistics\\b"),
          QStringLiteral("\\bstricteq\\b"),             QStringLiteral("\\bstringof\\b"),
          QStringLiteral("\\bstr_to_list\\b"),          QStringLiteral("\\bsum\\b"),
          QStringLiteral("\\bsupp_collect\\b"),         QStringLiteral("\\bsupp_expect\\b"),
          QStringLiteral("\\bsupp_query\\b"),           QStringLiteral("\\bsupp_value\\b"),
          QStringLiteral("\\bsv\\b"),                   QStringLiteral("\\bsys\\b"),
          QStringLiteral("\\bsystem_garbage\\b"),       QStringLiteral("\\btan\\b"),
          QStringLiteral("\\btempfile\\b"),             QStringLiteral("\\btimes\\b"),
          QStringLiteral("\\btq\\b"),                   QStringLiteral("\\btrue\\b"),
          QStringLiteral("\\btruncate\\b"),             QStringLiteral("\\bunion\\b"),
          QStringLiteral("\\buniv\\b"),                 QStringLiteral("\\bunivdict\\b"),
          QStringLiteral("\\buniv_name\\b"),            QStringLiteral("\\bvar\\b"),
          QStringLiteral("\\bvisible\\b"),              QStringLiteral("\\bw\\b"),
          QStringLiteral("\\bwh\\b"),                   QStringLiteral("\\bwq\\b"),
          QStringLiteral("\\bwrite\\b"),                QStringLiteral("\\bwriteq\\b"),
          QStringLiteral("\\bws\\b"),                   QStringLiteral("\\bwse\\b"),
          QStringLiteral("\\bwsc\\b"),                  QStringLiteral("\\bwspaces\\b"),
          QStringLiteral("\\bwsv\\b"),                  QStringLiteral("\\btq\\b"),
          QStringLiteral("\\b?\\b"),                    QStringLiteral("\\b!\\b"),
          QStringLiteral("\\b_\\b"),                    QStringLiteral("\\b\\|\\b"),
          };

  //clang-format on
    for (const QString &pattern: keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    // TODO: Double check these regex
    numberFormat.setForeground(QColor("#8cd0d3"));
    rule.pattern = QRegularExpression("\\b[-+]?[0-9]*\\.?[0-9]+\\b");
    rule.format = numberFormat;
    highlightingRules.append(rule);

    variableFormat.setForeground(QColor("#dfaf8f"));
    rule.pattern = QRegularExpression("\\b([0-9]*[A-Z_]+[0-9]*[a-z]*)\\b");
    rule.format = variableFormat;
    highlightingRules.append(rule);


    quotationFormat.setForeground(QColor("#cc9393"));
    rule.pattern = QRegularExpression("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(QColor("#709080"));
    rule.pattern = QRegularExpression("%[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(QColor("#709080"));

    commentStartExpression = QRegularExpression("/\\*");
    commentEndExpression = QRegularExpression("\\*/");
}
/*
 * Do we care that "QRegularExpressionPrivate::doMatch(): called on an invalid QRegularExpression object"
 * gets spammed for every character typed?
*/
void Highlighter::highlightBlock(const QString &text) {
    for (const HighlightingRule &rule: qAsConst(highlightingRules)) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    setCurrentBlockState(0);
    int startIndex = 0;
    if (previousBlockState() != 1) {
        startIndex = text.indexOf(commentStartExpression);
    }

    while (startIndex >= 0) {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
   }
}
