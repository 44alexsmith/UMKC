import os.path
import math

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
    
    Total = 0
    Count = 0
    for line in text: 
        words = line.split()
        for word in words: 
            word = clean_up(word)
            if word: 
                Total += len(word) 
                Count += 1
    return Total/Count
    
    

def type_token_ratio(text):
    ''' Return the type token ratio (TTR) for this text.
    TTR is the number of different words divided by the total number of words.
    text is a non-empty list of strings each ending in \n.
    At least one line in text contains a word. '''
  
    # To do: Replace this function's body to meet its specification.
    Uniques = [] 
    Count = 0 
    for line in text: 
        words = line.split() 
        for word in words: 
            word = clean_up(word) 
            if word: 
                Count += 1
                if word not in Uniques: 
                    Uniques.append(word) 
        
    return len(Uniques)/Count
    
                
def hapax_legomana_ratio(text):
    ''' Return the hapax_legomana ratio for this text.
    This ratio is the number of words that occur exactly once divided
    by the total number of words.
    text is a list of strings each ending in \n.
    At least one line in text contains a word.'''
 
    # To do: Replace this function's body to meet its specification.
    Counter = dict() 
    for line in text: 
        words = line.split() 
        for word in words: 
            word = clean_up(word) 
            if word in Counter: 
                Counter[word] += 1
            else:
                Counter[word] = 1
    # Counter now has a count of how many times each word occurs. 
    AppearOnces = len([w for w in Counter if Counter[w] == 1]) # list comprehension! 
      # Make a list of all words appearing once, find length of that list. 
    TotalWords = sum([Counter[w] for w in Counter]) 
      # add count of all words. 
    
    return AppearOnces / TotalWords 

def split_on_separators(original, separators):
    ''' Return a list of non-empty, non-blank strings from the original string
    determined by splitting the string on any of the separators.
    separators is a string of single-character separators.'''
    
    result = [original]
    temp = [] 
    for sep in separators: 
        for item in result: 
            TList = item.split(sep) 
            for thing in TList: 
                thing = clean_up(thing)
                temp.append(thing) 
        result = temp[:]
        temp = []
    return result
    
def average_sentence_length(text):
    ''' Return the average number of words per sentence in text.
    text is guaranteed to have at least one sentence.
    Terminating punctuation defined as !?.
    A sentence is defined as a non-empty string of non-terminating
    punctuation surrounded by terminating punctuation
    or beginning or end of file. '''
    
    Count= 0
    TotalLength = 0 
    Bigtext = ' '.join(text)
    Sentences = split_on_separators(Bigtext, '!?.')
    for OneSent in Sentences: 
        temp = []
        words = OneSent.split()
        for word in words: 
            word = clean_up(word)
            if word:
                temp.append(word) 
        Count += 1 # 1 more sentence 
        TotalLength += len(temp)  # containing this many words
            
    return TotalLength/Count 
    

def avg_sentence_complexity(text):
    '''Return the average number of phrases per sentence.
    Terminating punctuation defined as !?.
    A sentence is defined as a non-empty string of non-terminating
    punctuation surrounded by terminating punctuation
    or beginning or end of file.
    Phrases are substrings of a sentences separated by
    one or more of the following delimiters ,;: '''
    
    # To do: Replace this function's body to meet its specification.
    Sentences = split_on_separators(text, '!?.') 
    NSentences = 0 
    NPhrases = 0 
    for sentence in Sentences: 
        NSentences += 1 
        NPhrases += len(split_on_separators(sentence, ',;:'))
    return NPhrases / NSentences
    
    
def get_valid_filename(prompt):
    '''Use prompt (a string) to ask the user to type the name of a file. If
    the file does not exist, keep asking until they give a valid filename.
    Return the name of that file.'''
    
    # To do: Complete this function's body to meet its specification.
    again = True 
    while again: 
        filename = input(prompt)
        if os.path.exists(filename): 
            again = False
        else:  # file not found 
            print("That file does not exist.") 
    return filename
    
        
def read_directory_name(prompt):
    '''Use prompt (a string) to ask the user to type the name of a directory. If
    the directory does not exist, keep asking until they give a valid directory.
    '''
    again = True 
    while again: 
        dirname = input(prompt)
        if os.path.isdir(dirname): 
            again = False 
        else:  # not found, or isn't a directory 
            print("That directory does not exist.") 
            
    return dirname

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
    Total = 0 
    for idx in range(1, len(sig1)):
        Total += abs(sig1[idx]-sig2[idx]) * weight[idx]
    return  Total
    

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

    # readlines gives us a list of strings one for each line of the file
    text = open(mystery_filename, 'r').readlines()
    
    # calculate the signature for the mystery file
    #print("Calculating signature....") 
    mystery_signature = [mystery_filename]
    #print("Calculating average word length....") 
    mystery_signature.append(average_word_length(text))
    #print("Calculating type-token ratio....") 
    mystery_signature.append(type_token_ratio(text))
    #print("Calculating hapax legomana ratio....") 
    mystery_signature.append(hapax_legomana_ratio(text))
    #print("Calculating average sentence length....") 
    mystery_signature.append(average_sentence_length(text))
    #print("Calculating average sentence complexity....") 
    mystery_signature.append(avg_sentence_complexity(' '.join(text)))
    
    weights = [0, 11, 33, 50, 0.4, 4]
    
    prompt = 'enter the path to the directory of signature files: '
    sig_dir = read_directory_name(prompt)
    # every file in this directory must be a linguistic signature
    files = os.listdir(sig_dir)

    # we will assume that there is at least one signature in that directory
    this_file = files[0]
    signature = read_signature('{}/{}'.format(sig_dir,this_file))
    best_score = compare_signatures(mystery_signature, signature, weights)
    best_author = signature[0]
    for this_file in files[1:]:
        signature = read_signature('{}/{}'.format(sig_dir,this_file))
        score = compare_signatures(mystery_signature, signature, weights)
        if score < best_score:
            best_score = score
            best_author = signature[0]
    print( "best author match: {} with score {}".format(best_author, best_score))
    
