#we moving to python cause pointer matrixes give me headaches

#we read the file matrix by matrix and check if the operation table is associative
read_file=open("all_matrices.txt", "r")
write_file=open("associative_matrices.txt", "w")

def check_associative(n, matrix):
    for i in range(0, n):
        for j in range(0, n):
            for k in range(0, n):
                if matrix[i][matrix[j][k]]!=matrix[matrix[i][j]][k]:
                    return False
    return True

def get_matrix_size():
    return int(read_file.readline())

def read_matrix(n):
    matrix = []
    for i in range(0, n):
        matrix.append(list(map(int, read_file.readline().split())))

def write_matrix(n, matrix):
    for i in range(0, n):
        for j in range(0, n):
            write_file.write(str(matrix[i][j])+" ")
        write_file.write("\n")

def main():
    n=get_matrix_size()
    for i in range(0, n):
        matrix=read_matrix(n)
        if check_associative(n, matrix):
            write_matrix(n, matrix)

if __name__ == "__main__":
    main()
    read_file.close()
    write_file.close()
