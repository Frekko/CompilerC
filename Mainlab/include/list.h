#ifndef LAB_LIST_H
#define LAB_LIST_H

#include "heap.h"

#define LISTSIZE 10

class List
{
public:
	List(int _element_size, int _element_count = LISTSIZE);
	~List();

	void*      get(int pos); // �������� ������ �� ������� � ������� pos (������� �� �������)
	void       add(void* data); // ��������� �������, �� ������� ��������� data (��� ���� ������ �����)

	// returns and deletes elements
	void       take_first(void* store); // ���� �� ����� ������ ������� � ������� �� �����
	void       take_last(void* store); // ���� �� ����� ��������� ������� � ������� �� �����
	void       take(int pos, void* store); // ���� �� ����� ������� � ������� pos � ������� �� �����
	void       sort(bool dir = true, int(*method)(const void*, const void*) = 0); // ��������� ���� ��� method - ������� ��������� ��������� �����

	int        count(); // ���������� ���������� ��������� � �����
    bool       error() { return _error; } // true if error in last operation
private:
	struct Segment
	{
		void*    data;
		Segment* prev;
		Segment* next;
	};
	struct Segment*  first; // ������ �� ������ ������� ������
	struct Segment*  last; // ������ �� ��������� ������� ������
	int              first_index; // ������ ������� �������� (����� ���������� ��� take_first)
	int              last_index; // ������ ���������� �������� (����� ���������� ��� take � take_last)

	int              element_size; // ������ �������� � ������
	int              element_count; // ���������� ��������� � ����� �������� �����
    bool             _error; // ������
	
	void new_segment(); // ������� ��� �������� ������ �������� (��������� � �����)
	void delete_segment(Segment* seg); // ������� �������� �������� �� ������
};

#endif