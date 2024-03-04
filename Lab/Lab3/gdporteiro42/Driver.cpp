#include "Song.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

//LOOK!!  ENTER YOUR FUNCTION PROTOTYPES HERE
void insertionSort(Song [], int);
void reverseBubbleSort(Song [], int);
void quickSort(Song [], int, int);
int partition(Song [], int, int);

int main()
{
	Song *mySongArray;
	mySongArray = new Song[150000];
	int numSongs = 0;
	float length;
	string temp;
	
	ofstream outFile;
	ifstream inFile;

	time_t start, end;
	char filename[50];
	cout << "\n\nWhat is the name of the file with songs? (example.txt)\n";
	cin >> filename;
	inFile.open(filename);
	
	if(!inFile)
	{
		cout << "\n\nSorry, I can't open the file" << filename << endl << endl;
		exit(1);
	}
	
	while(getline(inFile, temp) && numSongs != 150000)
	{
		mySongArray[numSongs].setTitle(temp);

		if(!getline(inFile, temp)) break;
		mySongArray[numSongs].setArtist(temp);

		if(!(inFile >> length)) break;
		inFile.ignore();

		mySongArray[numSongs].setLength(length);
		numSongs++;
	}
	cout << "\n\nYou have created " << numSongs << " Song objects.\n\n";
	
	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   
	
	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertionSort(mySongArray, numSongs);
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	reverseBubbleSort(mySongArray, numSongs);
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	quickSort(mySongArray, 0, numSongs - 1);
	
	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outFile.open("sortFileQuick.txt");
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	delete [] mySongArray;
	return 0;
}

//LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertionSort(Song songs[], int totalSongs) {
	 // The item that is being sorting at the moment
	Song song;

	// The position where the Song should be inserted into the sorted array
	int j; 

	for (int i = 1; i < totalSongs; i++) {
		song = songs[i];
		j = i - 1;

		while (j >= 0 && songs[j].getTitle() > song.getTitle()) {
			songs[j + 1] = songs[j];
			j = j - 1;
		}

		songs[j + 1] = song;
	}

}


//LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE
void reverseBubbleSort(Song songs[], int totalSongs) {
	Song tempSongToSwap;

    for (int i = 0; i < totalSongs - 1; i++) {

        for (int j = 0; j < totalSongs - i - 1; j++) {

			// Swap the two adjacent elements if the one on the RIGHT is greater than the one on the LEFT (Because is a inverted Bubble sort)
            if (songs[j].getTitle() < songs[j+1].getTitle()) {
				tempSongToSwap = songs[j];
				songs[j] = songs[j + 1];
				songs[j + 1] = tempSongToSwap;
            }
        }
    }
}


//LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE
void quickSort(Song songs[], int low, int high) {
    int pivotLocation = 0;
	
	if (low < high) {
        pivotLocation = partition(songs, low, high);

        quickSort(songs, low, pivotLocation - 1);
        quickSort(songs, pivotLocation + 1, high);
    }
}


//LOOK!  WRITE YOUR PARTITION FUNCTION HERE
int partition(Song songs[], int left, int right) {
    Song pivot = songs[right];
	Song tempSong;

	// Index of the array's smaller element
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {

		// Check if the current element is smaller than the pivot
        if (songs[j].getTitle() <= pivot.getTitle()) {
            i++;
            tempSong = songs[i];
			songs[i] = songs[j];
			songs[j] = tempSong;
        }
    }

	// Swap the pivot into its correct position
    tempSong = songs[i + 1];
	songs[i + 1] = songs[right];
	songs[right] = tempSong;

    return (i + 1);
}
