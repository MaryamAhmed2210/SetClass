#include <iostream>
using namespace std;
class Set{
private:
    int *data;
    int noOfelements;
    int capacity;
public:
    Set(int cap = 5);
    Set(const Set &ref);
    ~Set();
    void insert(int value);
    void remove(int element);
    int getCardinality() const;
    Set calcUnion(Set &s2);
    Set calintersection(Set &s2);
    Set calcSymmetricDifference(Set &s2);
    void display() const;
};
Set::Set(int cap)
{
    if (cap <= 0)
        capacity = 5;
    else
        capacity = cap;

    noOfelements = 0;
    data = new int[capacity];
}
Set::Set(const Set &ref)
{
    capacity = ref.capacity;
    noOfelements = ref.noOfelements;
    data = new int[capacity];
    for (int i = 0; i < noOfelements; i++)
        data[i] = ref.data[i];
}
Set::~Set()
{
    delete[] data;
}
void Set::insert(int value)
{

    for (int i = 0; i < noOfelements; i++)
    {
        if (data[i] == value)
            return;
    }
    if (noOfelements < capacity)
    {
        data[noOfelements] = value;
        noOfelements++;
    }
}
void Set::remove(int element)
{
    for (int i = 0; i < noOfelements; i++)
    {
        if (data[i] == element)
        {
            data[i] = data[noOfelements - 1];
            noOfelements--;
        }
    }
}

int Set::getCardinality() const
{
    return noOfelements;
}

Set Set::calcUnion(Set &s2)
{
    Set result;
    for (int i = 0; i < noOfelements; i++)
	{
        result.insert(data[i]);
    }   
    for (int i = 0; i < s2.noOfelements; i++)
    {
		result.insert(s2.data[i]);
	}    
    return result;
}
Set Set::calintersection(Set &s2)
{
    Set result;

    for (int i = 0; i < noOfelements; i++)
    {
        for (int j = 0; j < s2.noOfelements; j++)
        {
            if (data[i] == s2.data[j])
                result.insert(data[i]);
        }
    }

    return result;
}
Set Set::calcSymmetricDifference(Set &s2)
{
    Set result;
    Set uni = calcUnion(s2);
    Set inter = calintersection(s2);
    for (int i = 0; i < uni.noOfelements; i++)
    {
        bool found = false;
        for (int j = 0; j < inter.noOfelements; j++)
        {
            if (uni.data[i] == inter.data[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
            result.insert(uni.data[i]);
    }

    return result;
}

void Set::display() const
{
    for (int i = 0; i < noOfelements; i++)
    {
		cout << data[i] << " ";
	}

    cout << endl;
}

int main()
{
    Set a(4);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    Set b(4);
    b.insert(7);
    b.insert(2);
    b.insert(3);
    b.insert(5);
    Set u = a.calcUnion(b);
    cout << "Union" << endl;
    u.display();
    cout << endl;
    Set i = a.calintersection(b);
    cout << "Intersection" << endl;
    i.display();
    cout << endl;
    cout << "Symmetric Difference" << endl;
    Set sm = a.calcSymmetricDifference(b);
    sm.display();

    return 0;
}