import graphviz

# Функция для чтения матрицы смежности из файла
def read_adj_matrix(file_path):
    with open(file_path, 'r') as f:
        adj_matrix = []
        for line in f:
            row = [int(x) for x in line.split()]
            adj_matrix.append(row)
        return adj_matrix

# Функция создания графа из матрицы смежности
def create_graph(adj_matrix):
    # Создаем новый ненаправленный граф
    dot = graphviz.Graph(strict=False)

    # Добавляем узлы в граф
    for i in range(len(adj_matrix)):
        dot.node(str(i))

    # Добавляем ребра в граф
    for i in range(len(adj_matrix)):
        for j in range(i, len(adj_matrix[i])):
            if adj_matrix[i][j] != 0:
                dot.edge(str(i), str(j), label=str(adj_matrix[i][j]))

    # Возвращаем граф
    return dot

# Пример использования
file_path = "matrix.txt"
adj_matrix = read_adj_matrix(file_path)
graph = create_graph(adj_matrix)
graph.view()
