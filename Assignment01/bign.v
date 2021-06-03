import os

fn main() {
	input_str := os.input_opt('Enter the height : ') or { panic(err.msg) }
	n := input_str.int()

	if n < 3 {
		println('Height must be at least 3')
		return
	}

	for row in 0 .. n {
		if row == 0 || row == n - 1 {
			print('N')
			for _ in 1 .. n - 1 {
				print(' ')
			}
			print('N')
		} else {
			print('N')
			for _ in 1 .. row {
				print(' ')
			}
			print('N')
			for _ in 2 .. n - row {
				print(' ')
			}
			print('N')
		}
		println('')
	}
}
