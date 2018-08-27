#pragma once

// hackerrank: Hotel Prices
// https://www.hackerrank.com/challenges/hotel-prices/problem
//
// In this challenge, the task is to debug the existing code to successfully
// execute all provided test files.
//
// The given code defines two classes HotelRoom and HotelApartment denoting
// respectively a standard hotel room and a hotel apartment. An instance of any
// of these classes has two parameters: bedrooms and bathrooms denoting
// respectively the number of bedrooms and the number of bathrooms in the room.
// The prices of a standard hotel room and hotel apartment are given as :
// Hotel Room : 50*bedrooms + 100*bathrooms
// Hotel Apartment : The price of a standard room with the same number bedrooms
// and bathrooms plus 100.
// In hotel's codebase, there is a piece of code reading the list of rooms 
// booked for today and calculates the total profit for the hotel. However, 
// sometimes calculated profits are lower than they should be.
// Debug the existing HotelRoom and HotelApartment classes' implementations so
// that the existing code computing the total profit returns a correct profit.
//
// Sample
// 2
// standard 3 1
// apartment  1 1
//
// 500

namespace hackerrank {

int hotel_prices ();

}
