
cb = [list(input()) for _ in range(8)]


N = 8 # (size of the chessboard)

def solveNQueens(board, col):
	if col == N:
		return 1

	ans = 0
	for i in range(N):
		if isSafe(board, i, col):
			board[i][col] = 1
			ans += solveNQueens(board, col + 1)
			board[i][col] = 0
	return ans

def isSafe(board, row, col):
	global cb
	if cb[row][col] == "*":
		return False
	for x in range(col):
		if board[row][x] == 1:
			return False
	for x, y in zip(range(row, -1, -1), range(col, -1, -1)):
		if board[x][y] == 1:
			return False
	for x, y in zip(range(row, N, 1), range(col, -1, -1)):
		if board[x][y] == 1:
			return False
	return True

board = [[0 for x in range(N)] for y in range(N)]
print(solveNQueens(board, 0))
