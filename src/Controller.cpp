// void show(UI ui)
// {
// 	const int pageSize = 20;													 // Number of columns to display per page
// 	int totalPages = (size + pageSize - 1) / pageSize; // Calculate total number of pages

// 	if (isEmpty())
// 	{
// 		std::cout << "Dynamic Array is empty." << std::endl;
// 		return;
// 	}

// 	char userInput;
// 	do
// 	{
// 		std::system("clear");
// 		ui.clearScreen();
// 		ui.universityHeader();
// 		// Display current page of data
// 		int start = currentIndex;
// 		int end = std::min(currentIndex + pageSize, size);

// 		for (int i = start; i < end; i++)
// 		{
// 			std::cout << array[i] << " ";
// 		}
// 		std::cout << std::endl;

// 		// Prompt user for navigation input
// 		std::cout << "Page " << (currentIndex / pageSize) + 1 << " of " << totalPages << std::endl;
// 		std::cout << "Enter 'n' for next page, 'p' for previous page, or any other key to exit: ";
// 		std::cin >> userInput;

// 		// Handle user input for navigation
// 		if (userInput == 'n')
// 		{
// 			if (currentIndex + pageSize < size)
// 				currentIndex += pageSize;
// 		}
// 		else if (userInput == 'p')
// 		{
// 			if (currentIndex - pageSize >= 0)
// 				currentIndex -= pageSize;
// 		}
// 		// Ignore any other input and exit the loop
// 	} while (userInput == 'n' || userInput == 'p');
// }