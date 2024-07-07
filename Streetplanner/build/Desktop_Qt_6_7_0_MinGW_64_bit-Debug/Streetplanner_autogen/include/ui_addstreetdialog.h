/********************************************************************************
** Form generated from reading UI file 'addstreetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTREETDIALOG_H
#define UI_ADDSTREETDIALOG_H

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

class Ui_AddStreetDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *input_City_from;
    QLabel *label_3;
    QLineEdit *input_City_to;

    void setupUi(QDialog *AddStreetDialog)
    {
        if (AddStreetDialog->objectName().isEmpty())
            AddStreetDialog->setObjectName("AddStreetDialog");
        AddStreetDialog->resize(400, 275);
        buttonBox = new QDialogButtonBox(AddStreetDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(AddStreetDialog);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 371, 157));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        input_City_from = new QLineEdit(formLayoutWidget);
        input_City_from->setObjectName("input_City_from");

        formLayout->setWidget(2, QFormLayout::FieldRole, input_City_from);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        input_City_to = new QLineEdit(formLayoutWidget);
        input_City_to->setObjectName("input_City_to");
        input_City_to->setClearButtonEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, input_City_to);

        QWidget::setTabOrder(input_City_from, input_City_to);

        retranslateUi(AddStreetDialog);

        QMetaObject::connectSlotsByName(AddStreetDialog);
    } // setupUi

    void retranslateUi(QDialog *AddStreetDialog)
    {
        AddStreetDialog->setWindowTitle(QCoreApplication::translate("AddStreetDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddStreetDialog", "Enter Street Info", nullptr));
        label_2->setText(QCoreApplication::translate("AddStreetDialog", "City From", nullptr));
        label_3->setText(QCoreApplication::translate("AddStreetDialog", "City To", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStreetDialog: public Ui_AddStreetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTREETDIALOG_H
