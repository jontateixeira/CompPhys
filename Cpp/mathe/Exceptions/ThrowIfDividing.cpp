/**
 * @file   : ThrowIfDividing.cpp
 * @author : Ernest Yeung
 * @email  : ernestyalumni@gmail.com
 * @brief  : A program to illustrate catching exceptions thrown by other procedures. 
 * @ref    : pp. 340 Program 15.3 Ch. 15 Odd and Ends; Edward Scheinerman, 
 *   C++ for Mathematicians: An Introduction for Students and Professionals. 
 *   Taylor & Francis Group, 2006. 
 *
 * If you find this code useful, feel free to donate directly and easily at this direct PayPal link: 
 * 
 * https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=ernestsaveschristmas%2bpaypal%40gmail%2ecom&lc=US&item_name=ernestyalumni&currency_code=USD&bn=PP%2dDonationsBF%3abtn_donateCC_LG%2egif%3aNonHosted 
 * 
 * which won't go through a 3rd. party such as indiegogo, kickstarter, patreon.  
 * Otherwise, I receive emails and messages on how all my (free) material on physics, math, and engineering have 
 * helped students with their studies, and I know what it's like to not have money as a student, but love physics 
 * (or math, sciences, etc.), so I am committed to keeping all my material open-source and free, whether or not 
 * sufficiently crowdfunded, under the open-source MIT license: 
 *  feel free to copy, edit, paste, make your own versions, share, use as you wish.    
 * Peace out, never give up! -EY
 * 
 * COMPILATION TIPS:
 *  g++ -std=c++17 -c factor.cpp
 * */
#include <iostream>

double quotient(double p, double q)
{
  if (q == 0.)
  {
    throw p;
  }
  return p/q;
}

int main() 
{
  double x, y;
  try 
  {
    std::cout << "Enter numerator: ";
    std::cin >> x;
    std::cout << "Enter denominator: "; 
    std::cint >> y;

    double q = quotient(x, y);

    std::cout << x << " divided by " << y << " is " << q << '\n';
  }
  catch (double top)
  {
    std::cerr << "Unable to divide " << top << " by zero" << '\n';
    exit(1);
  }

  std::cout << "Thank you for dividing." << std::endl;

  return 0;
}
