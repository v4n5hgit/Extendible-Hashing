# Product Search API with Qdrant Database

This repository provides tools to create a semantic search engine for product data using vector embeddings, FastAPI, Qdrant, HuggingFace, and OpenAI APIs.

## Overview

The project is divided into two primary components:

### 1. Vector Embedding Inserter
- **Objective**: Generate vector embeddings from product data in a CSV file and insert them into a Qdrant database.
- **Script**: `vector_embedding_inserter.py`

#### Functionality
- Processes 'bigBasketProducts.csv' to create embeddings for textual data fields such as 'product', 'category', etc.
- Utilizes SentenceTransformers framework to compute embeddings for over 100 languages.
- Inserts these embeddings into a Qdrant collection named "Products" for efficient retrieval and similarity searching.
- Outputs embedded data to 'output.csv'.

#### Code Explanation
- The script starts by loading the CSV data and using the SentenceTransformers library to create embeddings for specified text fields.
- It then establishes a connection with the Qdrant database and inserts these embeddings into the "Products" collection for future search operations.

### 2. FastAPI Application
- **Objective**: Provide a search API endpoint leveraging Qdrant's vector search and OpenAI's GPT-3.5 for natural language queries.
- **Script**: `main.py`

#### Functionality
- Defines a FastAPI application handling incoming requests and processing queries.
- Utilizes OpenAI API to break down natural language queries into structured JSON, representing product attributes.
- Implements a `/query-search` endpoint accepting POST requests with a 'query' field.
- Searches the Qdrant database for similar products based on query attributes.
- Returns the names of the top three matching products along with their IDs and scores.

#### Code Explanation
- The FastAPI application defines a route ('/query-search') that handles POST requests containing natural language queries.
- Upon receiving a query, it uses the OpenAI API to structure the query attributes and performs a search in the Qdrant database based on these attributes.
- The top three matching products with their IDs and scores are returned as a response.

## Getting Started

### Prerequisites
... [Prerequisites remain unchanged] ...

### Installation and Setup
... [Installation and Setup remain unchanged] ...

### Vector Embedding Script
... [Vector Embedding Script section remains unchanged] ...

### FastAPI Application
... [FastAPI Application section remains unchanged] ...

### Configuration
... [Configuration section remains unchanged] ...

## API Reference
... [API Reference section remains unchanged] ...

## Troubleshooting Steps
... [Troubleshooting Steps section remains unchanged] ...

## Conclusion
... [Conclusion section remains unchanged] ...
