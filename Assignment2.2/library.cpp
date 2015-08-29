// Put header/output stuff here.


#include "item.hpp"
#include "book.hpp"
#include "video.hpp"
#include "audiobook.hpp"
#include "library.hpp"

Library::Library()
{}

int Library::libraryMenu()
{

	std::cin.clear();
	std::cout << "Welcome to your personal library inventory assistant.\n\n";

	do
	{

		std::cout 	<< "Please select from the following options: \n\n"
			  	<< "*----------------------------------------------*\n\n"
			  	<< "A. Add Item\n"
				<< "D. Delete Item\n"
			  	<< "O. Open Library Inventory File.\n"
 			  	<< "S. Save Library Inventory File.\n"
			  	<< "Q. Quit Inventory Program. \n\n"
			  	<< "*----------------------------------------------*\n";

		std::cin.ignore(1024, '\n');
		std::cin.clear();

		std::cout << "Choice >> ";
		std::cin.get(menuOption);	// Will take first if correct, ignore rest. Otherwise, default to warning message.
		std::cin.ignore(1024, '\n');
		std::cin.clear();

		switch (menuOption)
		{
			case 'A':
			case 'a':
			{
				addItem();
				break;
			}

			case 'D':
			case 'd':
			{
				deleteItem(getItemID);
				break;
			}

			case 'O':
			case 'o':
			{
				openFile();
				break;
			}

			case 'S':
			case 's':
			{
				saveFile();
				break;
			}

			case 'Q':
			case 'q':
			{
				std::cout << "Are you sure you want to quit? >> ";
				std::cin >> quitVerification;		
				std::cin.ignore(1024, '\n');
				std::cin.clear();


				switch(quitVerification)
				{
					case 'Y':
					case 'y':
					{
					
						std::cout << "Have a nice day!" << std::endl;
						return 0;
						//exit(0);

					}

					case 'N':
					case 'n':
					{
						std::cout << "Returning to main menu..." << std::endl << std::endl << std::endl;
						break;
					}

				}

				break;

			}

			case '0': 
			{
				break; 
			}
			
			default: 
			{
				std::cout << "Invalid Input" << std::endl;
				break;
			}

		}

	}

	while(menuOption != 'Q' || 'q');
}


void Library::addItem()
{

		std::cout << "What sort of item is it? (1 = Book, 2 = Video, 3 = Audio Book, 0 to Quit)" << std::endl;
		std:: cout << "Input >> ";
		std::cin >> newItemClass;
		std::cin.ignore(1024, '\n');
		std::cin.clear();


		switch (newItemClass)
		{
			case 1: 
			{
				newBook();
				break;
			}
		
			case 2:
			{
				newVideo();
				break;
			
			}

			case 3:
			{
				newAudioBook();
				break;
			}

			case 0:
			{
				return;
			}

			default: 
			{
				std::cout << "Invalid Input" << std::endl;
				break;
			}
		}
	
	std::cout << "Item added!" << std::endl;
}

void Library::deleteItem(std::string getItemID)
{
	std::cout << "Item Deleted!" << std::endl;
}
void Library::saveFile()
{
	std::cout << "File Saved!" << std::endl;
}
void Library::openFile()
{
	std::cout << "File Loaded!" << std::endl;
}

void Library::getReserve()
{
	std::cout << "Book is reserved." << std::endl;
}



void Library::getItem(std::string itID)
{
	std::cout << "This is for us to get items... not so much to grab and yank. Ya know?" << std::endl;
	
}

void Library::newBook()
{
	Book* bk;
	
	std::cin.clear();
	std::cin.ignore(1024, '\n'); // Flush buffer.

	std::cout << "Adding new book... enter 0 to quit at any time." << std::endl;
	std::cout << "Item ID #: ";
	std::getline(std::cin, newItemID);
	
	if(newItemID == "0")
	{
		return;	
	}
	std::cin.clear();

	// Might want to check the ID before continuing -- if not unique, ask to put in a new one.
	std::cout << "Title: ";
	std::getline(std::cin, newTitle);
	std::cin.ignore(1024, '\n');
		std::cin.clear();


	if(newTitle == "0")
	{
		return;
	}

	std::cout << "Author: ";
	std::getline(std::cin, newAuthor);
	std::cin.ignore(1024, '\n');
	std::cin.clear();


	if(newAuthor == "0")
	{
		return;
	}
	std::cin.clear();
		
	std::cout << "Publisher: "; 
	std::getline(std::cin, newPublisher);
	std::cin.ignore(1024, '\n');
	std::cin.clear();

	if(newPublisher == "0")
	{
		return;
	}
	std::cin.clear();
	//while(newLength <= -1)
	// {
		std::cout << "Book Length in Pages: >> ";
		std::cin >> newLength;
		
	// }

	// while(newGenre <= -1 && newGenre > 8)
	//{
		std::cout << "Genre: \n"
				  <<" 1 = Fiction, 2 = Young Adult, 3 = Non-Fiction, 4= SciFi/Fantasy\n 5 = Biography/Autobiography, 6 = Mystery, 7 = Instructional, 8 = Humor/Funny\n";
		
		std::cin >> newGenre;
		
		if(newGenre <= -1 && newGenre > 8) 
		{
			std::cout << "Invalid input, try again.";
			std::cin.ignore(1024, '\n');
			std::cin.clear();
		}
		else
		{
			setGenre(newGenre);
		}
				
	// }
	// while(newFormat <= -1 && newFormat > 4)
		// {
		std::cout << "Format: \n"
				  << " 1 = Harcover, 2 = Paperback, 3 = Volume, 4 = Free-Leaf" << std::endl;
		std::cin >> newFormat;
	
		if(newFormat == 0)
		{
			return;
		}
		else if(newFormat == 1)
		{
			fmtBK = HARDCOVER;
		}
		else if(newFormat == 2)
		{
			fmtBK = PAPERBACK;
		}
		else if(newFormat == 3)
		{
			fmtBK = VOLUME;
		}
		else if(newFormat == 4)
		{
		fmtBK = FREE_LEAF;
		}
		else if(!std::cin.good())
		{
			std::cout << "Invalid input, try again.";
		}
		else
		{
			std::cout << "Invalid input, try again.";
		}


		std::cout << "Location: \n";

	// while(newLocale > -1 && newLocale < 11)
	// {
		std::cout << " 1 = On Shelves, 2 = On Reserve Shelf, 3 = On New Arrivals Shelf\n 4 = Checked Out, 5 = In Sorting, 6 = On Order, 7 = In Processing\n 8 = Lost, 9 = Due For Destruction, 10 = Overdue, 0 = Quit" << std::endl;
		
		std::cin >> newLocale;
		
		if(newLocale <= -1 && newLocale > 11)
		{
			std::cout << "Invalid output." << std::endl;
			std::cin.ignore(1024, '\n');
		}
		else
		{
		setLocale(newLocale);
		}
	//}

	bk = new Book(newItemID, newTitle, newAuthor, newPublisher, newLength, fmtBK, inGenre, inLocale, isReserved, isOut);
	std::cout << "Book added." << std::endl;

	std::cout << "//-------- DEBUG --------//"
			  << "Item ID: " << bk->getItemID() << std::endl
			  << "Title: " << bk->getTitle() << std::endl
			  << "Author: " << bk->getAuthor() << std::endl
			  << "Length: " << bk->getLength() << std::endl
			  << "Publisher " << bk->getPublisher() << std::endl
			  << "Genre: " << bk->getGenre(inGenre) << std::endl
			  << "Format: "<< bk->getFormatBK(fmtBK) << std::endl;


	// l.addBook(bk);

	libraryMenu();
}


void Library::newVideo()
{
	Video vid;

	std::cout << "Item ID #: ";
	std::getline(std::cin, newItemID);
	if(newItemID == "0")
		return;

	std::cout << "Title: ";

	std::getline(std::cin, newTitle);
	std::cout << "Director/Producer: ";
	std::getline(std::cin, newAuthor);
	std::cout << "Starring Actors: ";
	std::getline(std::cin, newActors);
	std::cout << "Production Studio: "; 
	std::getline(std::cin, newPublisher);
	
	// I would have put this in a function, but as it's unique to this object type for now, I decided not to.


	std::cout << "Genre: \n";	


	std::cout <<" 1= Action, 2 = Adventure, 3 = Animation, 4 = Kids/Children,\n 5 = Comedy, 6 = Romance, 7 = Documentary/Historical, 8 = Instructional\n";
	std::cin >> newGenre; 
		if(newGenre == 0)
		{
			return;
		}
		else if(newGenre == 1)
		{
			inGenreVID = ACTION;
		}
		else if(newGenre == 2)
		{
			inGenreVID = ADVENTURE;
		}
		else if(newGenre == 3)
		{
			inGenreVID = ANIMATION;	
		}
		else if(newGenre == 4)
		{
			inGenreVID = KIDS;
		}
		else if(newGenre == 5)
		{
			inGenreVID = COMEDY;
		}
		else if(newGenre == 6)
		{
			inGenreVID = ROMANCE;	
		}
		else if(newGenre == 7)
		{
			inGenreVID = DOCUMENTARY;
		}
		else if(newGenre == 8)
		{
			inGenreVID = INSTRUCTIONAL;	
		}
		else if(!std::cin.good())
		{
			std::cout << "Invalid input, try again.";
			std::cin.ignore(1024, '\n');
		}
		else
		{
			std::cout << "Invalid input, try again.";
			std::cin.ignore(1024, '\n');
		}
	std::cout << "Format: \n"
			  << " 1 = DVD, 2 = Blu-Ray Disc, 3 = Laserdisc, 4 = VHS, 5 = BetaMax" << std::endl;
	std::cin >> newFormat;
	
	while(newLengthHr <= -1 && newLengthHr >= 8)
	std::cout << "Length in Hours: " << std::endl;
	std::cin >> newLengthHr;
	{
		if(newLengthHr <= -1)
		{
			std::cout << "Video lengths cannot be negative." << std::endl;
		}
		else if(newLengthHr >= 8)	// The "Andy Warhol" Filter 
		{
			std::cout << "Movie Length Excessive: Break Into Volumes." << std::endl;
		}
	}

	while(newLengthMin <= -1 && newLength >= 60)
	{
		std::cout << "Length in Minutes: " << std::endl;
		std::cin >> newLengthHr;
		if(newLengthMin <= -1)
			{
			std::cout << "Video lengths cannot be negative." << std::endl;
			}
		else if(newLengthMin >= 60)	// If it goes to an hour 
			{
			std::cout << "If over 60 minutes, please convert to hour." << std::endl;
			}
	}
	
	std::cout << "Location: \n";
	while(newLocale > -1 && newLocale < 11)
	{
		if(newLocale > -1 && newLocale < 11)
		{
			std::cout << "Invalid output." << std::endl;
			std::cin.ignore(1024, '\n');
		}
		else
		{
			setLocale(newLocale);
		}
	}


	std::cout << "Audio Book Checked Out? (Y/N) >> " << std::endl; 
	std::cin >> newCheckedOut;

	return;

}
void Library::newAudioBook()
{
	AudioBook AB;

	std::cout << "Item ID #: ";
	std::cin >> newItemID;
	std::cout << "Title: ";
	std::getline(std::cin, newTitle);
	std::cout << "Author: ";
	std::getline(std::cin, newAuthor);
	std::cout << "Narrator: ";
	std::getline(std::cin, newNarrator);
	std::cout << "Publisher: "; 
	std::getline(std::cin, newPublisher);
	
	while(newGenre <= -1 && newGenre > 8)
	{
		std::cout << "Genre: \n"
				  <<" 1 = Fiction, 2 = Young Adult, 3 = Non-Fiction, 4= SciFi/Fantasy\n 5 = Biography/Autobiography, 6 = Mystery, 7 = Instructional, 8 = Humor/Funny\n";
		
		std::cin >> newGenre;
		if(newGenre <= -1 && newGenre > 8) 
		{
			std::cout << "Invalid input, try again.";
			std::cin.ignore(1024, '\n');
		}
		else
		{
			setGenre(newGenre);
		}
				
	}
	std::cout << "Format: \n"
			  << " 1 = Casette, 2 = CD, 3 = MP3, 4 = Digital Download" << std::endl;
	std::cin >> newFormat;
		if(newFormat == 3 || newFormat == 4)
			isDigital = true;
		else
			isDigital = false;

	std::cout << "Location: \n";
	while(newLocale > -1 && newLocale < 11)
	{
		if(newLocale > -1 && newLocale < 11)
		{
			std::cout << "Invalid output." << std::endl;
			std::cin.ignore(1024, '\n');
		}
		else
		{
		setLocale(newLocale);
		}
	}
	
	std::cout << "Audio Book Checked Out? (Y/N) ";
	std::cin.get(newCheckedOut);
	std::cin.ignore(1024, '\n');

	return;

}


Location Library::setLocale(int newLocale)
{
 	   
 	   	if(newLocale == 0)
		{
			libraryMenu();
		}

		else if (newLocale == 1)
		{
			inLocale = ON_SHELF;
		}

		else if (newLocale == 2)
		{
			inLocale = ON_RESERVE;
			isReserved = true;
		}

		else if (newLocale == 3)
		{
			inLocale = ON_NEW_SHELF;
			isNew = true;
		}
		else if (newLocale == 4)
		{
			inLocale = CHECKED_OUT;
			isOut = true;
		}

		else if(newLocale == 5)
		{
			inLocale = IN_SORTING;
		}
		else if(newLocale == 6)
		{
			inLocale = ON_ORDER;
			isNew = true;
		}

		else if (newLocale == 7)
		{
			inLocale = CHECKED_OUT;
			isOut = true;
		}

		else if (newLocale == 8)
		{
			inLocale = LOST;
			isOut = true;
		}

		else if (newLocale == 9)
		{
			inLocale = DUE_FOR_DESTRUCTION;
		}

		else if (newLocale == 10)
		{
			inLocale = OVER_DUE;
			isOut = true;
		}

	return inLocale;

}

Genre Library::setGenre(int newGenre)
{
		if(newGenre == 0)
		{
			libraryMenu();
		}
		else if(newGenre == 1)
		{
			inGenre = FICTION;
		}
		else if(newGenre == 2)
		{
			inGenre = YOUNG_ADULT;
		}
		else if(newGenre == 3)
		{
			inGenre = NON_FICTION;	
		}
		else if(newGenre == 4)
		{
			inGenre = SCIFI_FANTASY;
		}
		else if(newGenre == 5)
		{
			inGenre = BIOGRAPHY;
		}
		else if(newGenre == 6)
		{
			inGenre = MYSTERY;	
		}
		else if(newGenre == 7)
		{
			inGenre = INSTRUCTIONBK;
		}
		else if(newGenre == 8)
		{
			inGenre = HUMOR;	
		}

		return inGenre;

}