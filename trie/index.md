# Trie

A [trie](https://en.wikipedia.org/wiki/Trie) is a data structure that specializes in fast array lookups. It's traditionally used with strings, which is the only type this implementation supports. This library includes two types of generic tries: a [set version]({{site.baseurl/trie/trie-set}}) and a [map version]({{site.baseurl/trie/trie-map}}). For usage info, please see one of the respective version pages.

* [Set]({{site.baseurl/trie/trie-set}})
* [Map]({{site.baseurl/trie/trie-map}})

One might ask why they would use a trie over a normal map or a set. The main reasons (in the context of this library) is being able to efficiently store keys that start the same (i.e. "abolish" and "absolve") and the ability to iterate over all keys starting with a value (e.g. to iterate over all keys starting with "ab"). The latter is used in applications such as autocorrect on our phones (though autocorrect is more advanced and uses heuristics in addition to the starting letters).