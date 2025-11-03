#ifndef POPUP_H
#define POPUP_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPalette>
#include <QColor>
#include <QFontDatabase>
#include <QFont>

class Popup : public QWidget
{
    Q_OBJECT

public:
    explicit Popup(const QString& message, const QColor& color, QWidget *parent = nullptr);
    QFont m_customFont;
    QString applicationDirPath;

private:
    void loadCustomFont();

    void setupUI(const QString& message, const QColor& color);
};

#endif // POPUP_H
