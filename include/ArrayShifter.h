#include <Arduino.h>
class ArrayShifter
{
private:
    // String Reservoire Tank
    String _text;
    // a fixed size array of 5 in my case (depending on the amount of data you expect)
    String _viewPortArray[5];
    int _size = 0;
    // Methode to fill the array
    bool shiftArray(int position);
public:
    ArrayShifter(/* args */);
    // Method that gets the text from Serial
    String getSerialText();
    
    // get data from the array
    String getArrayData(int index);
    // array size getter
    int getSize();
    //clear the array
    void clearArray();
    //remove item
    void removeArrayItem(int index);
};

ArrayShifter::ArrayShifter(/* args */)
{
}

String ArrayShifter::getSerialText()
{
    // lesteing to the serial and returning the value
    _text = Serial.readString();
    return _text;
}
bool ArrayShifter::shiftArray(int position)
{
    /*Assuming that the data is comming separated with ";" for each row and ":" for each value
    to optimize the size of array in this way :
        name:value;age:value;gender:value;
    */
    String text = getSerialText();
    int index = 0;
    _size = 0;
    if (text.length() > 0) // text isn't empty
    {

        if (position <= 5) // if the data belongs to the first 5 range
        {

            for (int i = 0; i < 5; i++)
            {
                 // get the index of our separator that we've chosed to be ";"
                index = text.indexOf(";");
                if (index > 0)
                {
                    // index found
                    _size++;
                    // putting the value before ";" in the array
                    _viewPortArray[i] = text.substring(0, index);
                    // deleting the value from the tank
                    text = text.substring(index + 1);
                }
            }
        }
        else
        {
            _size = 0;
            // to wich range the desired index belongs
            unsigned int dataRange = ((position - position % 5));
            int ghostIndex = 0;
            // looping throught all ";" to get indexes
            for (int i = 0; i < dataRange; i++)
            {

                ghostIndex = text.indexOf(";");
                if (ghostIndex > 0)
                {
                    _size++;
                    text = text.substring(ghostIndex + 1);
                }
            }
            // grabing just 5 of the data
            for (int i = 0; i < 5; i++)
            {
                if (ghostIndex > 0)
                {
                    _size++;
                    _viewPortArray[i] = text.substring(0, ghostIndex);
                    text = text.substring(ghostIndex + 1);
                }

                // updating ghost index
                ghostIndex = text.indexOf(';');
            }
        }
        return true;
    }
    return false;
}
String ArrayShifter::getArrayData(int index)
{

    // turn the roulette
    if (shiftArray(index))
    {
        if (index <= 5)
        {
            // yes we have this
            return _viewPortArray[index];
        }
        else
        {
            // but we have to put it in the range of 5
            index = index - 5;
            return _viewPortArray[index];
        }
    }
}
int ArrayShifter::getSize()
{
    return _size;
}
 void ArrayShifter::clearArray()
 {
    for(int i  = 0 ; i <5 ; i ++)
    {
        _viewPortArray->remove(i);
        _size = 0;
    }
    
 }
 void ArrayShifter::removeArrayItem(int index)
 {
    _viewPortArray->remove(index);
    _size--;
 }