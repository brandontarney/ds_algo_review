/*
   * HASHING
   *	- Implement hashing example with collision
   *	- O(1) + hash-collision solution (e.g. re-hashing, chaining, or linear probing
	*	- Works best with prime numbers
	*	- Chaining by default since each "bucket" is a list
	*		- Rehasing alternative could apply hash to the resulting key-hash
   *
   */

#include<iostream>
#include<fstream>
#include<list>

using namespace std;

struct Item 
{
	int key;
	int value;
	Item(const int key, const int value);
	const bool operator==(Item& otherItem);
};

Item::Item(const int key, const int value)
{
	this->key = key;
	this->value = value;
}

const bool Item::operator==(Item& otherItem)
{
	return ( (this->key == otherItem.key) && 
			(this->value == otherItem.value) );
}

class HashTable
{
	int numberOfBuckets;
	list<Item> * table;

public:
	HashTable(const int numBuckets);
	~HashTable();

	void insertItem(Item & insertItem);
	void deleteItem(Item & deleteItem);
	const int hashFunction(int key); //returns the index from the hash
	void displayHashTable();
	void printToFile(ofstream & outputFile);
};

HashTable::HashTable(const int numBuckets)
{
	this->numberOfBuckets = numBuckets;
	table = new list<Item>[this->numberOfBuckets]; //array of lists, basically
}

HashTable::~HashTable()
{
	if (this->table != NULL)
	{
		delete[] (this->table);
		this->table = NULL;
	}
}

void HashTable::insertItem(Item & insertItem)
{
	const int bucketIndex = this->hashFunction(insertItem.key);
	this->table[bucketIndex].push_back(insertItem);
}

void HashTable::deleteItem(Item & deleteItem)
{
	const int bucketIndex = this->hashFunction(deleteItem.key);
	list<Item>::iterator listItr = 
		this->table[bucketIndex].begin();
	for (listItr; listItr != ( this->table[bucketIndex].end() ); listItr++)
	{
		if (*listItr == deleteItem)
		{
			break;
		}
	}

	//If we had a match, erase it
	if (listItr != this->table[bucketIndex].end())
	{
		this->table[bucketIndex].erase(listItr);
	}
}

void HashTable::displayHashTable()
{
	for (int i = 0; i < this->numberOfBuckets; i++)
	{
		cout << i << endl;
		for (auto x : table[i])
		{
			cout << "    " << x.key << " --> " << x.value << endl;
		}
		cout << endl;
	}
}

void HashTable::printToFile(ofstream & outputFile)
{
	for (int i = 0; i < this->numberOfBuckets; i++)
	{
		outputFile << i << endl;
		for (auto x : table[i])
		{
			outputFile << "    " << x.key << " --> " << x.value << endl;
		}
		outputFile << endl;
	}
}

/*Various hash functions
  * Multiplication
  const int HashTable::hashFunction(int key)
  {
	  return (int)( (7 * key + 11) / this->numberOfBuckets );
  }
  */

/*
  * Division
  */
  const int HashTable::hashFunction(int key)
  {
	  return (int)(key % this->numberOfBuckets);
  }

/*
  * Folding
  *		Combine using AND, OR, XOR, etc
  * Mid-Square
  *		Calculate key * key & use mid portion of result as address (NOT GOOD METHOD)
  */

	
int main(int argc, const char* argv[] )
{
	Item sample[5] = { Item(15, 3), Item(11, 4), Item(27, 1111), Item(8,123456), Item(9, 56) };
	int sampleSize = sizeof(sample)/sizeof(sample[0]);

	ofstream tmpOutputFile;
	tmpOutputFile.open("hashing_output.txt");

	cout << "sample size: " << sampleSize << endl;
	tmpOutputFile << "sample size: " << sampleSize << endl;

	HashTable hashTable(sampleSize*2);//artificially make 2x as many buckets as starting samples - helps avoid collisions
	for (int i = 0; i < sampleSize; i++)
	{
		hashTable.insertItem(sample[i]);
	}
	hashTable.displayHashTable();
	hashTable.printToFile(tmpOutputFile);

	tmpOutputFile.close();

	return (0);
}


