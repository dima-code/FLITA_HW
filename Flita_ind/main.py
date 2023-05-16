import numpy as np
import matplotlib.pyplot as plt
import time

def generate_adjacency_matrix(n):
    return np.random.randint(0, 5, size=(n, n))

def find_multiple_edges(matrix):
    multiple_edges = np.argwhere(matrix > 1)
    return multiple_edges

def measure_time(n):
    matrix = generate_adjacency_matrix(n)
    start = time.time()
    multiple_edges = find_multiple_edges(matrix)
    end = time.time()
    return end - start, len(multiple_edges)

def plot_time_vs_n():
    n_values = range(0, 2200, 10)
    times = [measure_time(n)[0] for n in n_values]

    plt.figure(figsize=(10, 6))
    plt.plot(n_values, times, label='Time to find multiple edges')
    plt.xlabel('Size of adjacency matrix (n)')
    plt.ylabel('Time (seconds)')
    plt.title('Time to find multiple edges in adjacency matrix of size n')
    plt.legend()
    plt.grid(True)
    plt.show()

values = [100, 200, 300, 500, 1000, 1200, 1500, 2000, 10000, 12000]
if __name__ == '__main__':
    for i in values:
        time_taken, multiple_edges_count = measure_time(i)
 #       print(f"Time for n = {i}: {time_taken} seconds, multiple edges found: {multiple_edges_count}")
    plot_time_vs_n()
    print('success')
