/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_Heading;
    QLabel *label_From;
    QLineEdit *input_CityFrom;
    QLabel *label_To;
    QLineEdit *input_CityTo;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName("SearchDialog");
        SearchDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(SearchDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setCursor(QCursor(Qt::ArrowCursor));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(SearchDialog);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 371, 157));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_Heading = new QLabel(formLayoutWidget);
        label_Heading->setObjectName("label_Heading");
        label_Heading->setCursor(QCursor(Qt::ArrowCursor));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_Heading);

        label_From = new QLabel(formLayoutWidget);
        label_From->setObjectName("label_From");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_From);

        input_CityFrom = new QLineEdit(formLayoutWidget);
        input_CityFrom->setObjectName("input_CityFrom");

        formLayout->setWidget(2, QFormLayout::FieldRole, input_CityFrom);

        label_To = new QLabel(formLayoutWidget);
        label_To->setObjectName("label_To");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_To);

        input_CityTo = new QLineEdit(formLayoutWidget);
        input_CityTo->setObjectName("input_CityTo");
        input_CityTo->setClearButtonEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, input_CityTo);

        QWidget::setTabOrder(input_CityFrom, input_CityTo);

        retranslateUi(SearchDialog);

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QCoreApplication::translate("SearchDialog", "Dialog", nullptr));
        label_Heading->setText(QCoreApplication::translate("SearchDialog", "Dijkstra wayfinder:", nullptr));
        label_From->setText(QCoreApplication::translate("SearchDialog", "From: ", nullptr));
        label_To->setText(QCoreApplication::translate("SearchDialog", "To: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
