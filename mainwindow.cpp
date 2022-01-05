/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  Program symulujący rzut kostką                                         *
 *  Copyright (C) 2020  Łukasz "Kuszki" Dróżdż  lukasz.kuszki@gmail.com    *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the  Free Software Foundation, either  version 3 of the  License, or   *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This  program  is  distributed  in the hope  that it will be useful,   *
 *  but WITHOUT ANY  WARRANTY;  without  even  the  implied  warranty of   *
 *  MERCHANTABILITY  or  FITNESS  FOR  A  PARTICULAR  PURPOSE.  See  the   *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have  received a copy  of the  GNU General Public License   *
 *  along with this program. If not, see http://www.gnu.org/licenses/.     *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "mainwindow.hpp" // Nagłówek okna głównego
#include "ui_mainwindow.h" // Wygenerowany interfejs

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent) // Wywołanie konstruktora klasy bazowej
	, ui(new Ui::MainWindow) // Utworzenie obiektu interfejsu
{
	ui->setupUi(this); // Budowanie interfejsu

	// Otwarcie pliku z ustawieniami
	QSettings settings("PI", "Random");

	// Wejście do grupy "roll"
	settings.beginGroup("roll");

	// Pobranie wartości z ustawień/wartości domyślnych
	m_max = settings.value("max", 6).toInt();
	m_min = settings.value("min", 1).toInt();

	// Zamknięcie grupy "roll"
	settings.endGroup();
}

MainWindow::~MainWindow(void)
{
	// Otwarcie pliku z ustawieniami
	QSettings settings("PI", "Random");

	// Wejście do grupy "roll"
	settings.beginGroup("roll");

	// Zapis aktualnych wartości w ustawieniach
	settings.setValue("max", m_max);
	settings.setValue("min", m_min);

	// Zamknięcie grupy "roll"
	settings.endGroup();

	delete ui; // Usunięcie interfejsu
}

void MainWindow::on_roll_clicked(void)
{
	// Wygenerowanie wartości pseudolosowej z wybranego zakresu
	int num = QRandomGenerator::system()->bounded(m_min, m_max+1);

	// Wygenerowanie napisu + zastosowanie odpowiednich tłumaczeń
	ui->label->setText(tr("Rolled %n eyelet(s)", nullptr, num));
}

void MainWindow::on_options_clicked(void)
{
	// Utworzenie dielogu ustawień
	SettingsDialog* dialog = new SettingsDialog(
					m_min, // Wartość początkowa `min`
					m_max, // Wartość początkowa `max`
					this); // Rodzic (właściciel) dialogu

	// Połaczenie zdarzenia "zakończono dialog"
	// z niszczeniem dialogu (zwolnienie zasobów)
	connect(dialog, &QDialog::finished,
		   dialog, &QDialog::deleteLater);

	// Połaczenie zdarzenia "zaakceptowano nowe wartości"
	// z aktualizacją parametrów w głównym oknie
	connect(dialog, &SettingsDialog::on_accepted,
		   this, &MainWindow::on_dialog_accepted);

	// Otwarcie dialogu w trybie modalnym (blokuje rodzica)
	dialog->open();
}

void MainWindow::on_dialog_accepted(int min, int max)
{
	m_min = min; // Aktualizacja minimum
	m_max = max; // Aktualizacja maksimum
}

