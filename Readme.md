# Product Search API with Qdrant Database

This repository contains tools to build a semantic search engine for product data using vector embeddings, FastAPI, Qdrant, HuggingFace, and OpenAI APIs.

## Overview

The project is split into two core parts:

### 1. Vector Embedding Inserter
- **Objective**: Generates vector embeddings from product data in a CSV file and inserts them into a Qdrant database.
- **Script**: `vector_embedding_inserter.py`

### 2. FastAPI Application
- **Objective**: Provides a search API endpoint utilizing Qdrant's vector search and OpenAI's GPT-3.5 for natural language processing.
- **Script**: `main.py`

## Getting Started

### Prerequisites

Ensure you have the following installed:

- Python 3.8+
- FastAPI
- Uvicorn (for serving the FastAPI application)
- Qdrant (running on localhost or a remote server)
- OpenAI API key

### Installation and Setup

1. **Clone the repository:**
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```

2. **Install Dependencies:**
    ```bash
    pip install -r requirements.txt
    ```

3. **Run Qdrant:**
    - Pull the Qdrant image:
        ```bash
        docker pull qdrant/qdrant
        ```
    - Run the Qdrant service:
        ```bash
        docker run -p 6333:6333 -p 6334:6334 \
            -v $(pwd)/qdrant_storage:/qdrant/storage:z \
            qdrant/qdrant
        ```

4. **Install SentenceTransformers:**
    ```
