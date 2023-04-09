#include <iostream>
#include <string>

struct movies {
	std::string title;
	int year;
	std::string genre;
	unsigned int duration;
	unsigned int price;
};

void show_movie(const movies& film) {
	std::cout << "Title:    " << film.title << '\n';
	std::cout << "Year :    " << film.year << '\n';
	std::cout << "Genre:    " << film.genre << '\n';
	std::cout << "Duration: " << film.duration << " min\n";
	std::cout << "Price:    " << film.price << " RUB\n\n";
}

movies expensive(const movies& film1, const movies& film2, const movies& film3) {
	unsigned int max_price = film1.price;
	const movies* ptr = &film1;
	if (film2.price > max_price) {
		max_price = film2.price;
		ptr = &film2;
	}
	if (film3.price > max_price) {
		max_price = film3.price;
		ptr = &film3;
	}
	return *ptr;
}

void update_info(movies& film) {
	std::cout << "Select a section to edit:\n" << "1 - Title\n" << "2 - Year\n" << "3 - Genre\n" << "4 - Duration\n" << "5 - Price\n" << "-> ";
	int section;
	std::cin >> section;
	switch (section) {
	case 1:
		std::cout << "Enter new title -> ";
		std::cin.ignore();
		std::getline(std::cin, film.title);
		break;
	case 2:
		std::cout << "Enter new release year -> ";
		std::cin >> film.year;
		break;
	case 3:
		std::cout << "Enter new genre -> ";
		std::cin.ignore();
		std::getline(std::cin, film.genre);
		break;
	case 4:
		std::cout << "Enter new duration (in minutes) -> ";
		std::cin >> film.duration;
		break;
	case 5:
		std::cout << "Enter new disk price (in RUB) -> ";
		std::cin >> film.price;
		break;
	default:
		std::cout << "\nSection not found. No changes done!\n\n";
		return;
	}
	std::cout << "\nDisk info updated.\n\n";
}

int main() {
	movies film1{ "Forrest Gump", 1994, "comedy-drama", 142, 300 };
	movies film2{ "Saving Private Ryan", 1998, "war film", 170, 350 };
	movies film3{ "Knives Out", 2019, "mystery film", 130, 400 };
	show_movie(film1);
	show_movie(film2);
	show_movie(film3);
	
	std::cout << "The most expensive disk costs " << expensive(film1, film2, film3).price << " RUB.\n\n";
	
	std::cout << "Do you want to edit any disk info (Y/N)? ";
	char answer;
	std::cin >> answer;
	const int qty = 3;
	movies arr[qty]{ film1, film2, film3 };
	int disk_choice;
	while (std::tolower(answer) == 'y') {	// Cycle for editing info as long as user wishes to
		std::cout << "Select disk number to edit info:\n";   
		for (int i = 0; i < qty; i++)
			std::cout << i + 1 << " - " << arr[i].title << '\n';
		std::cout << "(or press 0 to exit) -> ";
		do {	// Cycle for correct disk choice
			std::cin >> disk_choice;
			if (disk_choice >= 0 && disk_choice <= qty)
				break;
			else {
				std::cout << "No such disk found!\nPlease repeate you choice -> ";
				continue;
			}
		} while (true);
		if (disk_choice == 0)
			break;
		for (int i = 0; i < qty; i++) {
			if (disk_choice == i + 1) {
				std::cout << std::endl;
				show_movie(arr[i]);
				update_info(arr[i]);
				show_movie(arr[i]);
				break;
			}
		}
		std::cout << "Do you wish to continue editing (Y/N)? ";
		std::cin >> answer;
	}
	std::cout << "\nEnd of program.\n";

	return 0;
}