# Cache Simulator Project Description

# Overview

This Cache Simulator project is designed to mimic the behavior of a computer's memory cache system. The project implements fundamental concepts such as cache hits, cache misses, cache updates, and eviction of least occurred memory when the cache becomes full. The goal of the project is to simulate how data is stored, accessed, and evicted in a cache to improve memory access times.

In this project, the system consists of a parent memory that holds a larger set of memory addresses, and a cache that holds a subset of those addresses. The simulator tracks cache hits and misses and modifies the cache by evicting the least used memory when necessary.

# Key Features:
   1) Cache Simulation: Tracks memory addresses as they are accessed, adding them to the cache if they are not already present.
   2) Cache Hit: If an address is found in the cache, it’s considered a "hit."
   3) Cache Miss: If an address is not found in the cache, it’s considered a "miss" and added to the cache.
   4) Least Occurred Deletion: When the cache becomes full, the least occurred (least frequently accessed or least recently used) memory addresses are evicted to make room for new data.
   5) Modified Cache: The cache keeps track of modified memory addresses that have been recently accessed or added to the cache.
# Components
# 1. Allocator Class:
  The Allocator class simulates memory allocation. It is responsible for allocating blocks of memory, which are stored as pointers (char*). This class is a basic representation of a memory allocation system, and it provides:
  
  Methods to allocate memory of different sizes.
  A method to print the allocated addresses.
  A method to retrieve all allocated addresses for use in cache simulations.
  Key Functions:
  memory_allocate(size_t size): Allocates a memory block of the specified size.
  allocate_memory(size_t size): Allocates a memory block of a smaller size and adds it to the list of allocated addresses.
  printAllocatedaddresses(): Displays all the allocated memory addresses.
  getAllocatedaddresses(): Retrieves all the allocated memory addresses.
# 2. Cache Simulator Class:
  The Cache_simulator class is the core of this project. It handles the cache simulation, including the logic for cache hits, misses, and eviction of least occurred memory. The main responsibilities of this class are:
  
  Tracking the number of hits and misses.
  Modifying the cache when new memory addresses are added.
  Evicting the least occurred memory when the cache is full.
  Providing statistics on cache performance.
  # Key Functions:
  1) stats(vector<char*>& parent, vector<char*>& cache): Tracks the cache hits and misses. It compares the parent memory with the cache memory and records whether each address was a hit or miss.
  2) update(vector<char*>& parent, vector<char*>& cache): Updates the cache by adding memory addresses that missed in the cache and evicting the least occurred ones if the cache is full.
  3) print_missout_cache(): Prints the memory addresses that were missed in the cache.
  4) print_modified_cache(): Prints the modified memory addresses that have been recently accessed or added to the cache.
  5) print_least_occured(): Prints the least occurred addresses, i.e., those that have not been accessed recently and are candidates for eviction.
  6) get_stats(vector<char*> parent): Prints the hit and miss statistics in percentage based on the total size of the parent memory.
  7) Logic of Cache Modification and Least Occurred Deletion
  8) Cache Hits and Misses
     The cache hit occurs when a memory address being requested already exists in the cache. This means the system doesn't need to fetch the memory from the main memory again, saving time. The cache miss happens when the requested memory 
     address is not in the cache, requiring the system to add the address to the cache.
          
          # Cache Miss Handling

          When a cache miss occurs:
          
          The memory address that was missed is added to the cache.
          The modified memory list is updated to reflect this new addition.
          The cache may become full as new addresses are added.
          If the cache reaches its limit, least occurred memory addresses (those that have not been accessed in a while) are removed to make space for new data.

          # Least Occurred Memory Deletion

          When the cache is full, the simulator looks at the least occurred memory to evict. These are addresses that have been accessed less frequently or not recently. The simulator maintains a list of such addresses (least_occurred). When a new 
          address is added to the cache, and there is not enough space:
          
          The system checks for the least occurred address.
          The address that has not been accessed or found in the cache recently is evicted.
          The evicted address is removed from both the cache and modified memory.


