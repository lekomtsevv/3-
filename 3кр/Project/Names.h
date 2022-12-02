#pragma once

enum class InputMode : int {
	console_by_hand = 1,
	console_random = 2,
	io_file = 3

};

enum class SortId {
	bubble_sort_id = 1,
	selection_sort_id,
	insertion_sort_id,
	shell_sort_id,
	quick_sort_id
};