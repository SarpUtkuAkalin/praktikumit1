#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

/**
 * @brief Checks if the input fields are empty
 *
 * @return return true if the input fields are empty
 */
bool SearchDialog::inputEmpty() {
    return (ui->input_CityFrom->text().isEmpty() || ui->input_CityTo->text().isEmpty());
}

/**
 * @brief Returns city name from the "from" input field.
 *
 * @return QString city name.
 */
QString SearchDialog::getCityFrom() {
    return ui->input_CityFrom->text();
}

/**
 * @brief Returns the city name from the "to" input field
 *
 * @return QString city name.
 */
QString SearchDialog::getCityTo() {
    return ui->input_CityTo->text();
}

/**
 * @brief SearchDialog::on_input_CityFrom_textChanged
 * @param arg1
 */
void SearchDialog::on_input_CityFrom_textChanged(const QString &arg1) {
    City_From = arg1;
}

/**
 * @brief SearchDialog::on_input_CityTo_textChanged
 * @param arg1
 */
void SearchDialog::on_input_CityTo_textChanged(const QString &arg1) {
    City_To = arg1;
}

/**
 * @brief Slot for the accept button.
 */
void SearchDialog::on_buttonBox_accepted() {
    done(QDialog::Accepted);
}

/**
 * @brief Slot for the reject button.
 */
void SearchDialog::on_buttonBox_rejected() {
    done(QDialog::Rejected);
}
