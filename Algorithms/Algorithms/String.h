#pragma once
class String
{
public:
	String(char* content);
	~String();
private:
	char* value;
public:
	int Search(String* pattern);
	int GetLength();
private:
	int Fail(String* pattern, int index);
};

