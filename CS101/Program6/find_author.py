'''Course: CS 101
 Assignment: Program 6 
 filename: find_author.py
 Name: Alexeo Smith
 Email: asd5b@mail.umkc.edu
 Due : Nov 10th, 2013

 Problem:
 Professional methods of authorship detection are a good deal more complicated than what we're going to use here, but even with the simple methods we're using here, your program can make some reasonable predictions about authorship.
You are provided with a skeleton program containing stubs for most of the functions you will need, with part of the main program logic already completed. The program runs but doesn't do much of anything. You will need to complete the program by filling in the missing pieces. The program will ask the user for the name of a file containing an unknown text to be analyzed. Your program will compute the linguistic signature for the mystery file, compare it to the profiles of all known authors, and report which author the text most closely matches.

Algorithm:
1)	As instructed, place the provided author signature files in a subdirectory of the 
    folder where the Python program(.py) file will be 
2) Place the provided mystery text files in the same directory as the Python program   
     file
3) The program will continue to prompt the user for a text file that has a sample  
     writing of an unknown author until the user provides a valid text file. 
     Then the program will read the text file as a huge string and call the 
     split_on_separators function on the string
4) Next the program will prompt the user for the directory containing the signature  
     files, confirm it’s a valid directory, move to that folder, read the files and store
     result in a list called files
5) After reading the signature files, the program will move back to the starting  
     folder 
6) Per the provided docstring specifications, complete each incomplete function and
     add additional docstrings. Don’t use any for loops for the get_valid_filname and  
     read_directory_name functions. Don’t use continue or break statements in any 
     functions.  Don’t modify existing functions beyond the provided specifications
7) Call provided functions where applicable and don’t add any different linguistic  
     features
8) Run the program, which will then compare the unknown author text file to  
     profiles of known actors, then report which author the text closely matches'''



import os.path, math, string
separators_str = ".!?"

def clean_up(s):
    ''' Return a version of string str in which all letters have been
    converted to lowercase and punctuation characters have been stripped 
    from both ends. Inner punctuation is left untouched. '''
    
    punctuation = '''!"',;:.-?)([]<>*#\n\t\r'''
    result = s.lower().strip(punctuation)
    return result


def average_word_length(text):
    ''' Return the average length of all words in text. Do not
    include surrounding punctuation in words. 
    text is a non-empty list of strings each ending in \n.
    At least one line in text contains a word.'''
    
    # To do: Replace this function's body to meet its specification.
    #for sentences in text:

    if text:
        words = text.split()
        average = sum(map(len, words))/len(words)
        return average
    else:    
        return 1.0
    

def type_token_ratio(text):
    ''' Return the type token ratio (TTR) for this text.
    TTR is the number of different words divided by the total number of words.
    text is a non-empty list of strings each ending in \n.
    At least one line in text contains a word. '''
  
    # To do: Replace this function's body to meet its specification.
    
    for p in string.punctuation:
        text = text.replace(p, "")
        text = clean_up(text)
            
    if text:
        text = text.split()
        count_dict = {}
        for word in text:
            if word in count_dict:
                count_dict[word] += 1
            else:
                count_dict[word] = 1           
        return len(count_dict)/len(text)
    else:
        return 1
        
                
def hapax_legomana_ratio(text):
    ''' Return the hapax_legomana ratio for this text.
    This ratio is the number of words that occur exactly once divided
    by the total number of words.
    text is a list of strings each ending in \n.
    At least one line in text contains a word.'''
 
    # To do: Replace this function's body to meet its specification.
    count = 0
    for p in string.punctuation:
        text = text.replace(p, "")
        text = clean_up(text)
       
    if text:
        text = text.split()
        count_dict = {}
        for word in text:
            if word in count_dict:
                count_dict[word] += 1
            else:
                count_dict[word] = 1

    for k,v in count_dict.items():
     if count_dict[k] == 1:
        count +=1

    ratio = count/len(text)
    if ratio:
        return ratio
    else:
        return 1

def split_on_separators(original, separators):
    ''' Return a list of non-empty, non-blank strings from the original string
    determined by splitting the string on any of the separators.
    separators is a string of single-character separators.'''
    
    sentences_lst =[]
    # To do: Complete this function's body to meet its specification.
    # You are not required to keep the two lines below but you may find
    # them helpful. (Hint)
    essay_lst = original.replace(separators_str[0],'#').replace(separators_str[1],'#').replace(separators_str[2],'#').split("#")
    essay_lst = [x.strip(' ') for x in essay_lst]
    essay_lst = [x for x in essay_lst if x != '']
    for i in range(len(essay_lst)):
           if essay_lst[i][-1] != ":" and essay_lst[i][-1] != ";" and essay_lst[i][-1] != "," :
             sentences_lst.append(essay_lst[i]) 

    return sentences_lst
                
    
def average_sentence_length(text):
    ''' Return the average number of words per sentence in text.
    text is guaranteed to have at least one sentence.
    Terminating punctuation defined as !?.
    A sentence is defined as a non-empty string of non-terminating
    punctuation surrounded by terminating punctuation
    or beginning or end of file. '''
    
    # To do: Replace this function's body to meet its specification.
    if text:
        sentences = split_on_separators(text, separators_str)
        average = sum(map(len, sentences))/len(sentences)
        return average
    else:    
        return 1
    

def avg_sentence_complexity(text):
    '''Return the average number of phrases per sentence.
    Terminating punctuation defined as !?.
    A sentence is defined as a non-empty string of non-terminating
    punctuation surrounded by terminating punctuation
    or beginning or end of file.
    Phrases are substrings of a sentences separated by
    one or more of the following delimiters ,;: '''
    
    # To do: Replace this function's body to meet its specification.
    phrase_separators_str = ":,;"
    phrases_lst = []
    if text:
        sentences_lst = split_on_separators(text, separators_str)
        sentences_str = ",".join(sentences_lst)
        phrase_lst = sentences_str.replace(phrase_separators_str[0],'#').replace(phrase_separators_str[1],'#').replace(phrase_separators_str[2],'#').split("#")
        phrase_lst = [x.strip(' ') for x in phrase_lst]
        phrase_lst = [x for x in phrase_lst if x != '']
        result = sum(map(len,phrase_lst))/len(split_on_separators(text, separators_str))
        return result
    else:
        return 1.0
            
    
def get_valid_filename(prompt):
    '''Use prompt (a string) to ask the user to type the name of a file. If
    the file does not exist, keep asking until they give a valid filename.
    Return the name of that file.'''

    # Uncomment and use this statement as many times as needed for input:
    # filename = input(prompt)
    # Uncomment and use this statement as many times as needed for output:
    # print "That file does not exist."
    # Do not use any other input or output statements in this function.
    
    noFile = True
    # To do: Complete this function's body to meet its specification.
    while noFile:
        filename = input(prompt)
        if os.path.isfile(filename):
            noFile = True
            return filename
        else:
            print("That file does not exist.")

    
def read_directory_name(prompt):
    '''Use prompt (a string) to ask the user to type the name of a directory. If
    the directory does not exist, keep asking until they give a valid directory.
    '''

    # Uncomment and use this statement as many times as needed for input:
    # dirname = input(prompt)
    # Uncomment and use this statement as many times as needed for output:
    # print "That directory does not exist."
    # Do not use any other input or output statements in this function.
    
    noDirectory = True
    # To do: Complete this function's body to meet its specification.
    while noDirectory:
        dirname = input(prompt)
        if os.path.isdir(dirname):
            noDirectory = False
            return dirname
        else:
            print("That directory does not exist.")
   
def compare_signatures(sig1, sig2, weight):
    '''Return a non-negative real number indicating the similarity of two 
    linguistic signatures. The smaller the number the more similar the 
    signatures. Zero indicates identical signatures.
    sig1 and sig2 are 6 element lists with the following elements
    0  : author name (a string)
    1  : average word length (float)
    2  : TTR (float)
    3  : Hapax Legomana Ratio (float)
    4  : average sentence length (float)
    5  : average sentence complexity (float)
    weight is a list of multiplicative weights to apply to each
    linguistic feature. weight[0] is ignored.
    '''
    # To do: Replace this function's body to meet its specification.
    compute_lst = []
    if sig1 and sig2:
        End = False
        i = 5
        while i != 0:
            compute_lst.append(abs((sig1[i]-sig2[i])*weights[i]))
            i -= 1
        result = sum(compute_lst)
        return result
    else:
        return  0.0
    

def read_signature(filename):
    '''Read a linguistic signature from filename and return it as 
    list of features. '''
    
    file = open(filename, 'r')
    # the first feature is a string so it doesn't need casting to float
    result = [file.readline()]
    # all remaining features are real numbers
    for line in file:
        result.append(float(line.strip()))
    return result
        

if __name__ == '__main__':
    
    prompt = 'enter the name of the file with unknown author:'
    mystery_filename = get_valid_filename(prompt)
    
    # readlines gives us the file as a list of strings each ending in '\n'
    text = open(mystery_filename, 'r').read()
    #text.close() 
    # calculate the signature for the mystery file
    mystery_signature = [mystery_filename]
    mystery_signature.append(average_word_length(text))
    mystery_signature.append(type_token_ratio(text))
    mystery_signature.append(hapax_legomana_ratio(text))
    mystery_signature.append(average_sentence_length(text))
    mystery_signature.append(avg_sentence_complexity(text))
    
    weights = [0, 11, 33, 50, 0.4, 4]

    files = []
    prompt = 'enter the path to the directory of signature files: '
    dirRead = read_directory_name(prompt)
    # every file in this directory must be a linguistic signature
    # to do: Get list of all files in directory name we just got.
    # store it in a list called 'files'
    
    files = os.listdir(dirRead)
    
		
    # we will assume that there is at least one signature in that directory
    this_file = files[0]
    signature = read_signature('{}\\{}'.format(dirRead,this_file))
    best_score = compare_signatures(mystery_signature, signature, weights)
    best_author = signature[0]
    for this_file in files[1:]:
        signature = read_signature('{}\\{}'.format(dirRead,this_file))
        score = compare_signatures(mystery_signature, signature, weights)
        if score < best_score:
            best_score = score
            best_author = signature[0]
    print( "best author match: {} with score {}".format(best_author, best_score))
    
