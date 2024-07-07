/********************************************************************************
** Form generated from reading UI file 'addcitydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCITYDIALOG_H
#define UI_ADDCITYDIALOG_H

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

class Ui_AddCityDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *input_name;
    QLineEdit *input_y;
    QLabel *label_2;
    QLineEdit *input_x;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *AddCityDialog)
    {
        if (AddCityDialog->objectName().isEmpty())
            AddCityDialog->setObjectName("AddCityDialog");
        AddCityDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddCityDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(AddCityDialog);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 371, 157));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        input_name = new QLineEdit(formLayoutWidget);
        input_name->setObjectName("input_name");

        formLayout->setWidget(2, QFormLayout::FieldRole, input_name);

        input_y = new QLineEdit(formLayoutWidget);
        input_y->setObjectName("input_y");

        formLayout->setWidget(4, QFormLayout::FieldRole, input_y);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        input_x = new QLineEdit(formLayoutWidget);
        input_x->setObjectName("input_x");
        input_x->setClearButtonEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, input_x);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        QWidget::setTabOrder(input_name, input_x);
        QWidget::setTabOrder(input_x, input_y);

        retranslateUi(AddCityDialog);

        QMetaObject::connectSlotsByName(AddCityDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCityDialog)
    {
        AddCityDialog->setWindowTitle(QCoreApplication::translate("AddCityDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddCityDialog", "Enter new city info", nullptr));
        label_2->setText(QCoreApplication::translate("AddCityDialog", "City name", nullptr));
        label_3->setText(QCoreApplication::translate("AddCityDialog", "City X Coordinate", nullptr));
        label_4->setText(QCoreApplication::translate("AddCityDialog", "City Y Coordinate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCityDialog: public Ui_AddCityDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCITYDIALOG_H
