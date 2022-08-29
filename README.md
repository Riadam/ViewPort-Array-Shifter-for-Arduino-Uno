# ViewPort-Array-Shifter-for-Arduino-Uno
One of the issues you may face while programming arduino uno with c++, is the need of unknown size array or let say a kind of infinite size array.
all solutions you can find are turning around allocating memory and using pointers , which is not preferred in our case, because arduino uno with Atm 328
has only 2kb of ram and using pointers or allocating memory means that the memory you allocate can not be used by other things at run time
yes, you can free this memory but you cannot guarantee that the ram will not be full and the arduino will not crash.

What to do then ?
the answer to this is pretty simple, instead of thinking in how to define an unknown size array, we should just create a limited size array and shift it through
a source of data that can hold a large size of values without problem, just like taking multiple photos because one photo can't cover everybody
https://github.com/Riadam/ViewPort-Array-Shifter-for-Arduino-Uno/blob/master/SwYJTpVXL3qUKYLOZaRf_enhancedbuzz10300136345906812.jpg

assuming that we are receiving data from the serial (sent from another arduino for example), this data should be normalized, or separated in a way we can 
loop through it and store it based on a separator
the size of limited array we create will depends on the median of the data rows count you may receive (you should think about this)
