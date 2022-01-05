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

#include <QLibraryInfo> // Informacje o bibliotekach
#include <QApplication> // Główna klasa aplikacji
#include <QLocale> // Klasa obsługująca lokalizacje
#include <QTranslator> // Klasa obsługująca tłumaczenia

int main(int argc, char *argv[])
{
	QApplication a(argc, argv); // Utworzenie obiektu aplikacji

	QTranslator translator; // Utworzenie obiektu translatora dla programu
	QTranslator qtTranslator; // Utworzenie obiektu translatora dla obiektów Qt
	QTranslator baseTranslator;// Utworzenie obiektu translatora dla bazy Qt

	// Pobranie listy języków z ustawień lokalnego użytkownika
	const QStringList uiLanguages = QLocale::system().uiLanguages();

	// Wyszukiwanie dostępnych tłumaczeń
	for (const QString &locale : uiLanguages)
	{
		// Generowanie nazwy pliku z tłumaczeniami wybranego języka
		const QString name = QLocale(locale).name();

		// Sprawdzenie, czy istniają tłumaczenia w wybranem języku
		if (translator.load(":/i18n/PI-Roll-Example_" + name))
		{
			// Załadowanie plików z tłumaczeniami Qt
			qtTranslator.load("qt_" + name, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
			baseTranslator.load("qtbase_" + name, QLibraryInfo::location(QLibraryInfo::TranslationsPath));

			// Załadowanie tłumaczeń do aplikacji
			a.installTranslator(&translator);
			a.installTranslator(&qtTranslator);
			a.installTranslator(&baseTranslator);

			break; // Zakończenie wyszukiwania
		}
	}

	MainWindow w; // Utworzenie okna głównego
	w.show(); // Wyświetlenie okna głównego

	return a.exec(); // Uruchomienie pętli programu
}
