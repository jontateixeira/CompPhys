# C++ examples related to Lippman, Lajoie, Moo's **C++ Primer**

(20160713) I'm reading and going through  

**C++ Primer** (5th Edition) 5th Edition, by Stanley B. Lippman, Josée Lajoie, Barbara E. Moo. Addison-Wesley Professional; 5 edition (August 16, 2012). ISBN-13: 978-0321714114   

which I'll refer to as Lippman, Lajoie, Moo (2012).  

| codename        | Chapter | Section         | Directory  | Description            |
| --------------- | :-----: | :-------------: | :--------- | :--------------------- |
| `pointers.cpp`  | 2       | 2.3.2. Pointers | `./`       | Pointers               |
| `ilconstexpr.cpp` | 2       | 2.4.4. `constexpr` and Constant Expressions   
			      6.5.2. Inline and `constexpr` Functions | `./` | `constexpr` |
| `vectors.cpp`    | 3 | *3.3. Library vector Type* | `../Cpp14/` | Everything about **vectors** for C++11/14, cf. Lippman, Lajoie, Moo, **C++ Primer** 5th ed.  |
| `vectors_binarysearch.cpp` | 3 | *3.4. Introducing Iterators*, 3.4.2 |  `../Cpp14/` | **classic algorithm, binary search, using vectors** via C++11/14, cf. Lippman, Lajoie, Moo, **C++ Primer** 5th ed.  |  
| `arrs.cpp` 	  | 3 	    | 3.5. Arrays 	 | `./` 	   | Arrays, pointers and arrays, pointer arithmetic on arrays, iterators, increment operators on arrays (and arrays as a pointer) 			|
| `unique_ptr.cpp` | 12     | 12.1.5         | `../Cpp14/` | cf. http://en.cppreference.com/w/cpp/memory/unique_ptr ; `std::unique_ptr`, `std::make_unique` examples |  

## Wrapping pointers to arrays with smart pointers, both `shared_ptr` and `unique_ptr` cases, with "custom" deleters/deconstructors  

### `shared_ptr`  
cf. https://stackoverflow.com/questions/13061979/shared-ptr-to-an-array-should-it-be-used
```  
    constexpr const size_t Lx = {1<<5};  // 2^5 = 32

    // shared_ptr
    //  Initialization
    std::shared_ptr<float> sp( new float[Lx]  );    
    std::shared_ptr<float> spb( new float[Lx],array_deleter<float>()  );    
    // with C++11, you can use std::default_delete partial specialization for array types instead of array_deleter
    std::shared_ptr<float> spc(new float[Lx],std::default_delete<float[]>());
    // use lambda expression instead of functors
    std::shared_ptr<float> spd(new float[Lx],[](float* p) { delete[] p; });

    // "boilerplate" initialization of interesting values
    for (auto iptr = spc.get(); iptr != spc.get() + Lx/2; iptr++) {
        *iptr = 11.f * ((int) (iptr - spc.get()));
    }

    for (float* b = spc.get(); b < spc.get() + Lx; b++) {
        std::cout << " b : " << b << " *b : " << *b << std::endl;
    }

    for (auto iptr = spc.get()+Lx/2; iptr != spc.get() + Lx; iptr++) {
        *iptr = 0.11f * ((int) (iptr - spc.get()));
    }

    for (float* b = spc.get(); b < spc.get() + Lx; b++) {
        std::cout << " b : " << b << " *b : " << *b << std::endl;
    }
    // array index access
    for (int idx = 0 ; idx < Lx; idx++) {
        std::cout << " " << idx << " : " << spc.get()[idx] << ", ";
    }
```  
### `unique_ptr`  
```  
    // unique_ptr, initialization

    auto uptr11 = std::unique_ptr<float[]>{ new float[Lx]};  // this will correctly call delete []
//    auto uptr14 = std::make_unique<float[]>(Lx);

    // with custom deleter/deconstructor
    auto deleter = [&](float* ptr){ delete[] ptr; }; 
    std::unique_ptr<float[], decltype(deleter)> up(new float[Lx], deleter);

    // "boilerplate" initialization of interesting values
    for (auto iptr = up.get(); iptr != up.get() + Lx/2; iptr++) {
        *iptr = 101.f * ((int) (iptr - up.get()));
    }

    for (float* b = up.get(); b < up.get() + Lx; b++) {
        std::cout << " b : " << b << " *b : " << *b << std::endl;
    }

    for (auto iptr = up.get()+Lx/2; iptr != up.get() + Lx; iptr++) {
        *iptr = 0.011f * ((int) (iptr - up.get()));
    }

    for (float* b = up.get(); b < up.get() + Lx; b++) {
        std::cout << " b : " << b << " *b : " << *b << std::endl;
    }
    // array index access
    for (int idx = 0 ; idx < Lx; idx++) {
        std::cout << " " << idx << " : " << up.get()[idx] << ", ";
    }

```  

