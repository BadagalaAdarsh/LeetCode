class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        # base case of the problem
        # if length of input list is 0 then return empty 2d list
        if len(strs) == 0:
            return [[""]]
        
        # initializing empty dictionary to store all the similar angrams
        # key-> sorted word, values -> list of the words which are angrams
        dictionary = dict()
        
        # traversing the given list over the strings
        for word in strs:
            # sorting the given string 
            sortedString = ''.join(sorted(word))
            
            # add the current word to the dictionary
            
            # if sortedString is already present in the dictionary then direcly add the current word
            if sortedString in dictionary.keys():
                dictionary[sortedString].append(word)
            
            # else add current sortedString as key and word a individual element of the list
            else:
                dictionary[sortedString] = [word]
                
        
        # to store the answer and return 
        finalAnswer = []
        
        # traverse the dictionary and group words of individual keys
        
        for key in dictionary.keys():
            # getting all the angrams one by one
            currentList = dictionary[key]
            
            # appending current list to our final answer
            finalAnswer.append(currentList)
            
        # return the answer
        return finalAnswer
        