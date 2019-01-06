/*	Convert header files for it-takes-two-advance's sprite groups to the correct
 *	format.
 *
 *	Files come in the format of a header guard, with several C arrays of floats:
 *	
 *	const u16 tx_ExampleSpriteData = {
 *		0x0000, 0x0001, 0x0002, ...	
 *	};
 *
 *	The array contents are in the wrong order to be memcpy'd directly.
 *	This program rights these wrongs.
 */

package com.danielilett.sprite_converter

import java.io.File

var isScanning : Boolean = false

// Entry point.
fun main(args: Array<String>)
{
	if(args.size < 2)
	{
		println("Please supply source and destination files as arguments.")
		return
	}

	convert(args[0], args[1])

	println("File successfully converted.")

	return
}

// Convert the contents of infile to the correct format, and save in outfile.
fun convert(inFilename: String, outFilename : String)
{
	val numbers = mutableListOf<String>()

	val infile = File(inFilename)
	
	File(outFilename).printWriter().use { out ->
		infile.forEachLine {
			if(!isScanning)
			{
				// Begin to scan for array contents.
				if(it.contains("[] = {"))
				{
					isScanning = true
					println("Start of entry.")
				}

				// Print the line regardless.
				out.println(it)
			}
			else
			{
				// Process collected numbers.
				if(it.contains("};"))
				{
					// Add each number in the line to the number list.
					numbers.addAll(getNumbers(it.replace("};", "")))

					isScanning = false
					println("End of entry.")

					// Print the correctly-ordered lines to the file.
					rearrangeList(numbers).forEach {
						out.println("\t" + it)
					}

					numbers.clear()

					out.println("};")
				}
				else
				{
					// Add each number in the line to the number list.
					numbers.addAll(getNumbers(it))
				}
			}
		}
	}

	return
}

// Find all number strings in the list and return them.
fun getNumbers(line : String) : MutableList<String>
{
	val numbers = mutableListOf<String>()

	// Add each number in the line to the number list.
	line.split(',').forEach {
		val cleanStr = it.trim()

		if(cleanStr.length > 0)
		{
			numbers.add(cleanStr + ",")
		}
	}

	return numbers
}

// Take values in groups of 4 and arrange accordingly.
fun rearrangeList(numbers: MutableList<String>) : MutableList<String>
{
	val groups = mutableListOf<String>()

	numbers.chunked(4).forEach {
		groups.add(it.joinToString(separator = " "))
	}

	val retGroups = groups.toMutableList()

	for(i in 0..groups.size - 1)
	{
		if(i < 16)
		{
			if(i % 2 == 0)
			{
				retGroups[i / 2] = groups[i]
			}
			else
			{
				retGroups[8 + i / 2] = groups[i]
			}
		}
		else
		{
			if(i % 2 == 0)
			{
				retGroups[16 + (i - 16) / 2] = groups[i]
			}
			else
			{
				retGroups[24 + (i - 16) / 2] = groups[i]
			}
		}
	}

	return retGroups
}
