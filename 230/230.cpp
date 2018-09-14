#include <iostream>
#include <string>
#include <regex>
#include <stack>

using namespace std;

struct book
{
	string author;
	string title;
	bool inLibrary;
};

int main()
{
	book library[1000];

	string line;
	int count = 0;

	regex reg("\"([^\"]*)\" by (.*).");

	while (getline(cin, line, '\n'))
	{
		if (line.find("END") == 0)
		{
			break;
		}

		smatch matches;
		regex_search(line, matches, reg);
		library[count].title = matches[1].str();
		library[count].author = matches[2].str();
		library[count].inLibrary = true;

		count++;
	}

	regex reg2("(\w) \"([^\"]*)\"");
	string line2;
	string shelve = "SHELVE";

	stack<string> returnedBooks;

	while (getline(cin, line2, '\n'))
	{
		if (line.find("END") == 0)
		{
			break;
		}

		// If it says SHELVE, this is our function.
		if (line2.compare(shelve) == 0)
		{
		imbadatcpp:
			while (!returnedBooks.empty())
			{
				string book = returnedBooks.pop();
				int place = 0;

				// find the placeholder of the book
				for (int i = 0; i < 1000; i++)
				{
					if (library[i].title.compare(book) == 0)
					{
						place = i;
					}
				}

				while (place != 0)
				{
					if (library[i - 1].inLibrary)
					{
						cout << "Put \"" << book << " after \"" << library[i - 1].title << "\"" << endl;
					}
				}
				cout << "Put " << title << " first" << endl;
				goto imbadatcpp;
			}
		}

		// else it says borrow or return, so do that here.
		smatch matches2;
		regex_search(line2, matches2, reg2);
		string borrow = "BORROW";
		string return_ = "RETURN";
		string borrowOrReturn = matches2[1].str();
		if (borrowOrReturn.compare(borrow) == 0)
		{
			int place = 0;

			// find the placeholder of the book
			for (int i = 0; i < 1000; i++)
			{
				if (library[i].title.compare(book) == 0)
				{
					place = i;
				}
			}
		}
	}
}